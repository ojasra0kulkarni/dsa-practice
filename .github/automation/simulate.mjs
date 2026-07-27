#!/usr/bin/env node
// Preview the schedule without touching git or the Gemini API.
//   node .github/automation/simulate.mjs [days] [start-date]
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

import { planDay, spreadCommits } from './lib/schedule.mjs';
import { makeRng } from './lib/rng.mjs';
import { istClock, toDate, gitDate } from './lib/time.mjs';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const config = JSON.parse(
  fs.readFileSync(path.join(HERE, 'config.json'), 'utf8').replace(/^﻿/, '')
);

const DAYS = Number(process.argv[2] || 365);
const START = process.argv[3] || new Date().toISOString().slice(0, 10);
const DOW = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'];

let d = new Date(Date.parse(`${START}T00:00:00Z`));
const hourHist = {};
const countHist = {};
let skips = 0;
let late = 0;
let totalProblems = 0;
let earliestCommit = Infinity;
let latestEnd = -Infinity;

console.log(`\nFirst 21 days from ${START}\n${'-'.repeat(74)}`);

for (let i = 0; i < DAYS; i++) {
  const key = d.toISOString().slice(0, 10);
  const p = planDay(key, config);

  if (i < 21) {
    console.log(
      `${key}  ${DOW[d.getUTCDay()]}  ${p.skip ? `— skipped (${p.reason})` : p.label}`
    );
  }

  if (p.skip) {
    skips++;
  } else {
    const h = Math.floor(((p.endMinute + 330) % 1440) / 60);
    hourHist[h] = (hourHist[h] || 0) + 1;
    countHist[p.count] = (countHist[p.count] || 0) + 1;
    totalProblems += p.count;
    if (p.late) late++;
    earliestCommit = Math.min(earliestCommit, p.startMinute);
    latestEnd = Math.max(latestEnd, p.endMinute);
  }
  d = new Date(d.getTime() + 86400000);
}

const active = DAYS - skips;

console.log(`\nWhen sessions wrap up (IST)\n${'-'.repeat(74)}`);
for (const h of Object.keys(hourHist).map(Number).sort((a, b) => a - b)) {
  const n = hourHist[h];
  console.log(`${String(h).padStart(2, '0')}:00  ${'▇'.repeat(Math.max(1, Math.round(n / 3)))} ${n}`);
}

console.log(`\nProblems per active day\n${'-'.repeat(74)}`);
for (const c of Object.keys(countHist).map(Number).sort((a, b) => a - b)) {
  console.log(`${c}  ${'▇'.repeat(Math.max(1, Math.round(countHist[c] / 3)))} ${countHist[c]}`);
}

console.log(`\nOver ${DAYS} days\n${'-'.repeat(74)}`);
console.log(`  active days      ${active}  (${skips} skipped)`);
console.log(`  problems solved  ${totalProblems}  (~${(totalProblems / active).toFixed(2)}/day)`);
console.log(`  late sessions    ${late}  (${((late / active) * 100).toFixed(1)}%)`);
console.log(`  earliest commit  ${istClock(START, earliestCommit)}`);
console.log(`  latest commit    ${istClock(START, latestEnd)}`);

// one worked example, timestamps exactly as git will record them
const sample = planDay(START, config);
if (!sample.skip) {
  const rng = makeRng(config.seed_salt, START, 'session').fork('extras');
  const n = sample.count + 2;
  const mins = spreadCommits(sample.startMinute, sample.endMinute, n, rng);
  console.log(`\nCommit stamps git would write on ${START}\n${'-'.repeat(74)}`);
  for (const m of mins) {
    console.log(`  ${gitDate(toDate(START, m, 12), config.timezone.offset_minutes, config.timezone.git_offset)}`);
  }
  const ok = mins.every((v, i) => i === 0 || v > mins[i - 1]);
  console.log(`\n  strictly increasing: ${ok}`);
  console.log(`  ends exactly at planned session end: ${mins[mins.length - 1] === sample.endMinute}`);
}
console.log();
