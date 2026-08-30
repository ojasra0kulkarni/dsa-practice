#!/usr/bin/env node
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

import { makeRng } from './lib/rng.mjs';
import { planDay, timingGate, spreadCommits } from './lib/schedule.mjs';
import {
  utcDateKey,
  utcMinutesNow,
  toDate,
  gitDate,
  istClock,
  istToUtcMinutes,
  shiftDayKey,
} from './lib/time.mjs';
import { flatten, pickNext } from './lib/sheet.mjs';
import { generateSolution } from './lib/gemini.mjs';
import {
  commitMessage,
  fixMessage,
  notesMessage,
  readmeMessage,
  persona,
  makeFollowUpEdit,
} from './lib/humanize.mjs';
import { renderReadme } from './lib/readme.mjs';
import { makeGit } from './lib/git.mjs';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const ROOT = path.resolve(HERE, '../..');

const argv = process.argv.slice(2);
const DRY_RUN = argv.includes('--dry-run');
const FORCE = argv.includes('--force');
const OFFLINE = argv.includes('--offline');
const NO_PUSH = argv.includes('--no-push') || DRY_RUN;

/** Stand-in for the model, so the git/timestamp plumbing can be tested for free. */
function offlineSolution(problem) {
  return {
    code: `#include <bits/stdc++.h>\nusing namespace std;\n\n// ${problem.name}\n// placeholder produced by --offline\n\nint main() {\n    return 0;\n}\n`,
    approach_tag: 'placeholder',
    approach_note: 'Offline placeholder, no model was called.',
    time_complexity: 'O(1)',
    space_complexity: 'O(1)',
    gotcha: 'nothing, this is a stub',
  };
}

const CONFIG_PATH = path.join(HERE, 'config.json');
const STATE_PATH = path.join(HERE, 'state.json');
const SHEET_PATH = path.join(HERE, 'problems.json');

// Editing config.json in Notepad or writing it from PowerShell prepends a
// UTF-8 BOM, which JSON.parse rejects outright. Strip it rather than let a
// stray byte take the whole schedule down.
const readJson = (p) => JSON.parse(fs.readFileSync(p, 'utf8').replace(/^﻿/, ''));
const writeJson = (p, v) => fs.writeFileSync(p, JSON.stringify(v, null, 2) + '\n');
const ensureDir = (p) => fs.mkdirSync(path.dirname(p), { recursive: true });
const relative = (p) => path.relative(ROOT, p).split(path.sep).join('/');

function loadState() {
  if (!fs.existsSync(STATE_PATH)) {
    return { done: [], revisits: {}, last_session_day: null, day_number: 0, recent: [] };
  }
  const s = readJson(STATE_PATH);
  s.done ||= [];
  s.revisits ||= {};
  s.recent ||= [];
  s.day_number ||= 0;
  return s;
}

async function main() {
  const config = readJson(CONFIG_PATH);
  const sheet = readJson(SHEET_PATH);
  const state = loadState();

  // DSA_BOT_NOW lets you replay a specific moment - useful for testing and
  // for backfilling a day the runner missed.
  const now = process.env.DSA_BOT_NOW ? new Date(process.env.DSA_BOT_NOW) : new Date();
  const todayKey = utcDateKey(now);
  const nowMinute = utcMinutesNow(now);

  console.log(`[${now.toISOString()}] probe — clock reads ${istClock(todayKey, nowMinute)}`);

  // GitHub does not deliver this cron reliably: of the 24 probes a day the
  // schedule asks for, a handful actually arrive, and they arrive late —
  // occasionally so late they cross midnight UTC. Such a probe used to read
  // the clock, decide it was "too early" for the NEW day, and exit, leaving
  // the day it was actually scheduled for unfinished for good. If yesterday
  // was a session day that never got committed, finish it before today.
  let dayKey = todayKey;
  let backfill = false;

  if (!FORCE && state.last_session_day && state.last_session_day !== todayKey) {
    const yesterdayKey = shiftDayKey(todayKey, -1);
    if (state.last_session_day < yesterdayKey && !planDay(yesterdayKey, config).skip) {
      dayKey = yesterdayKey;
      backfill = true;
      console.log(`backfilling ${yesterdayKey} — a session day that never landed`);
    }
  }

  if (state.last_session_day === dayKey && !FORCE) {
    console.log('already committed today, nothing to do');
    return;
  }

  const plan = planDay(dayKey, config);
  if (plan.skip) {
    if (!FORCE) {
      console.log(`skipping today — ${plan.reason}`);
      return;
    }
    console.log(`(forced past skip: ${plan.reason})`);
  }

  console.log(`plan: ${plan.label ?? 'forced run'}`);

  // A backfilled day is wholly in the past, so there is no window left to wait for.
  if (!FORCE && !backfill) {
    const gate = timingGate(plan, nowMinute, dayKey, config);
    if (!gate.go) {
      console.log(`waiting — ${gate.reason}`);
      return;
    }
    console.log(`go — ${gate.reason}`);
  }

  const apiKey = process.env.GEMINI_API_KEY;
  if (!apiKey && !OFFLINE) throw new Error('GEMINI_API_KEY is not set');

  const all = flatten(sheet, config.content.start_step);
  const rng = makeRng(config.seed_salt, dayKey, 'session');
  const picks = pickNext(all, state.done, plan.count ?? 1, rng, config.content, state.revisits);

  if (picks.length === 0) {
    console.log('nothing left to pick — check the sheet');
    return;
  }

  // Roll the extras up front so the real commit count is known before any
  // timestamp is handed out. Every commit must land in the past, in order.
  const extraRng = rng.fork('extras');
  const extras = picks.map(() => ({
    fix: extraRng.chance(config.content.followup_fix_chance),
    notes: extraRng.chance(config.content.notes_chance),
  }));
  const refreshReadme =
    extraRng.chance(config.content.readme_refresh_chance) ||
    Math.floor((state.done.length + picks.length) / 25) > Math.floor(state.done.length / 25);

  // The bookkeeping file only gets its own commit when a README refresh gives
  // it cover. Otherwise it is amended into the last solution commit, so the
  // history never shows a commit that touches nothing but bot state.
  const totalCommits =
    picks.length +
    extras.filter((e) => e.fix).length +
    extras.filter((e) => e.notes).length +
    (refreshReadme ? 1 : 0);

  // The plan sized the session for `count` problems. Fix-ups and notes add
  // commits, so stretch the session backwards at the same pace rather than
  // cramming six commits into nine minutes.
  // Clamp to the clock so nothing is stamped in the future — but only when the
  // session is today's. Yesterday's minutes are all already in the past, and
  // clamping them against this morning's clock would bunch them at midnight.
  const ceiling = backfill ? Infinity : nowMinute;
  const endMinute = Math.min(plan.endMinute ?? nowMinute, ceiling);
  const plannedSpread = (plan.endMinute ?? endMinute) - (plan.startMinute ?? endMinute);
  const perCommit = plan.count > 1 ? plannedSpread / (plan.count - 1) : 14;
  const floor = istToUtcMinutes(config.timing.hard_earliest_commit_ist);
  const startMinute = Math.max(floor, endMinute - Math.round(perCommit * (totalCommits - 1)));
  const commitMinutes = spreadCommits(startMinute, endMinute, totalCommits, extraRng);

  const tz = config.timezone;
  let commitIndex = 0;
  const nextStamp = () => {
    const minute = commitMinutes[Math.min(commitIndex++, commitMinutes.length - 1)];
    return gitDate(toDate(dayKey, minute, extraRng.int(0, 59)), tz.offset_minutes, tz.git_offset);
  };

  const git = makeGit(ROOT, DRY_RUN);
  const branch = process.env.TARGET_BRANCH || git.currentBranch();
  const dayNumber = state.day_number + 1;

  let lastStamp = null;
  const doCommit = (paths, message) => {
    git.add(paths);
    if (!git.hasStagedChanges() && !DRY_RUN) return false;
    lastStamp = nextStamp();
    git.commit(message, lastStamp);
    console.log(`  commit "${message}"  @ ${lastStamp}`);
    return true;
  };

  let solved = 0;
  const usedTemplates = new Set();

  for (let i = 0; i < picks.length; i++) {
    const problem = picks[i];
    const style = persona(rng.fork(`persona-${problem.index}`));
    console.log(`\n→ ${problem.name}  [step ${problem.step} · ${problem.section}]`);

    let gen;
    try {
      gen = OFFLINE
        ? offlineSolution(problem)
        : await generateSolution(problem, style, config.gemini, apiKey);
    } catch (err) {
      console.log(`  !! generation failed, skipping this one: ${err.message}`);
      continue;
    }

    const suffix = problem.revision ? `-v${problem.revision + 1}` : '';
    const filePath = path.join(
      ROOT,
      'solutions',
      problem.stepSlug,
      `${problem.slug}${suffix}.${config.content.extension}`
    );
    ensureDir(filePath);
    fs.writeFileSync(filePath, gen.code);
    doCommit([relative(filePath)], commitMessage(problem, gen, rng, dayNumber, usedTemplates));

    solved++;
    if (problem.revision) {
      state.revisits[problem.index] = problem.revision;
    } else {
      state.done.push(problem.index);
    }
    state.recent.push({ date: dayKey, name: problem.name, step: problem.step });

    // a real repo has follow-up commits: a typo fix, a forgotten note
    if (extras[i].fix) {
      fs.writeFileSync(filePath, makeFollowUpEdit(gen.code, problem, rng));
      doCommit([relative(filePath)], fixMessage(problem, rng));
    }

    // notes, but only sometimes — nobody journals every single day
    if (extras[i].notes) {
      const notesPath = path.join(ROOT, 'notes', `${problem.stepSlug}.md`);
      ensureDir(notesPath);
      const header = fs.existsSync(notesPath) ? '' : `# ${problem.stepTitle}\n`;
      const entry =
        `\n## ${problem.name}\n\n${gen.approach_note}\n\n` +
        `- ${gen.gotcha}\n- TC ${gen.time_complexity}, SC ${gen.space_complexity}\n`;
      fs.appendFileSync(notesPath, header + entry);
      doCommit([relative(notesPath)], notesMessage(problem, rng));
    }
  }

  if (solved === 0) {
    console.log('\nnothing generated successfully — leaving the repo untouched');
    process.exitCode = 1;
    return;
  }

  state.last_session_day = dayKey;
  state.day_number = dayNumber;
  state.recent = state.recent.slice(-40);

  // The state file rides along with the README refresh so the history never
  // shows a lone "update state.json" commit.
  writeJson(STATE_PATH, state);
  const readmePath = path.join(ROOT, 'README.md');

  if (refreshReadme) {
    fs.writeFileSync(readmePath, renderReadme(sheet, all, state, config));
    doCommit([relative(readmePath), relative(STATE_PATH)], readmeMessage(rng));
  } else {
    git.add([relative(STATE_PATH)]);
    if (lastStamp && (git.hasStagedChanges() || DRY_RUN)) {
      git.amend(lastStamp);
      console.log(`  (state folded into the previous commit)`);
    }
  }

  if (!NO_PUSH) {
    git.push(branch);
    console.log(`\npushed ${commitIndex} commit(s) to ${branch}`);
  } else {
    console.log(`\n[no push] ${commitIndex} commit(s) prepared`);
  }
}

main().catch((err) => {
  console.error(err);
  process.exit(1);
});
