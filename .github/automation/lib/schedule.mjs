import { makeRng } from './rng.mjs';
import { istToUtcMinutes, istWeekday, istClock } from './time.mjs';

function inBlackout(dayKey, streak) {
  for (const b of streak.blackouts || []) {
    if (dayKey >= b.from && dayKey <= b.to) return b.label;
  }
  const md = dayKey.slice(5);
  for (const b of streak.recurring_blackouts || []) {
    // handles ranges that wrap the new year, e.g. 12-28 -> 01-03
    const wraps = b.from > b.to;
    const hit = wraps ? md >= b.from || md <= b.to : md >= b.from && md <= b.to;
    if (hit) return b.label;
  }
  return null;
}

/**
 * Days immediately before an exam block get lighter, not silent - people
 * wind down, they don't slam the brakes.
 */
function taperFactor(dayKey, streak) {
  const days = streak.taper_days_before_blackout || 0;
  if (!days) return 1;
  for (let i = 1; i <= days; i++) {
    const probe = new Date(Date.parse(`${dayKey}T00:00:00Z`) + i * 86400000)
      .toISOString()
      .slice(0, 10);
    if (inBlackout(probe, streak)) return 0.5;
  }
  return 1;
}

/**
 * The day's plan. Deterministic for a given (dayKey, salt), so every cron
 * probe on that date agrees on it.
 */
export function planDay(dayKey, config) {
  const rng = makeRng(config.seed_salt, dayKey, 'plan');
  const t = config.timing;

  const blackout = inBlackout(dayKey, config.streak);
  if (blackout) return { skip: true, reason: `blackout: ${blackout}` };

  if (config.streak.random_skip_chance > 0 && rng.chance(config.streak.random_skip_chance)) {
    return { skip: true, reason: 'random rest day' };
  }

  // --- when does the session END ---------------------------------------
  const [pLo, pHi] = t.primary_window_ist.map(istToUtcMinutes);
  const [lLo, lHi] = t.late_window_ist.map(istToUtcMinutes);
  const peak = istToUtcMinutes(t.peak_ist);

  const late = !rng.chance(t.primary_weight);
  const endMinute = Math.round(
    late ? rng.bell(lLo, lHi) : rng.triangular(pLo, peak, pHi)
  );

  // --- how many problems ------------------------------------------------
  const dow = istWeekday(dayKey, endMinute);
  const isWeekend = dow === 0 || dow === 6;
  let count = Number(rng.weighted(isWeekend ? config.volume.weekend : config.volume.weekday));

  if (isWeekend && rng.chance(config.volume.grind_day_chance)) {
    const [gLo, gHi] = config.volume.grind_day_count;
    count = rng.int(gLo, gHi);
  }

  const taper = taperFactor(dayKey, config.streak);
  if (taper < 1) count = Math.max(1, Math.round(count * taper));

  // --- spacing between commits, walked backwards from the end ----------
  const [gLo, gHi] = config.volume.gap_minutes;
  const gaps = [];
  for (let i = 0; i < count - 1; i++) gaps.push(rng.int(gLo, gHi));

  const earliest = istToUtcMinutes(t.hard_earliest_commit_ist);
  const latest = istToUtcMinutes(t.hard_latest_commit_ist);
  let spread = gaps.reduce((a, b) => a + b, 0);

  const clampedEnd = Math.min(endMinute, latest);
  if (clampedEnd - spread < earliest) {
    // compress rather than start before the allowed floor
    const scale = (clampedEnd - earliest) / Math.max(spread, 1);
    for (let i = 0; i < gaps.length; i++) gaps[i] = Math.max(3, Math.floor(gaps[i] * scale));
    spread = gaps.reduce((a, b) => a + b, 0);
  }

  const startMinute = clampedEnd - spread;

  return {
    skip: false,
    late,
    isWeekend,
    count,
    endMinute: clampedEnd,
    startMinute,
    label: `${count} problem(s), session ${istClock(dayKey, startMinute)} -> ${istClock(dayKey, clampedEnd)}${late ? ' (late night)' : ''}`,
  };
}

/**
 * Lay `n` commits across the session, ascending, first at startMinute and
 * last at endMinute, with the spacing jittered so it never looks metronomic.
 * Called once the real commit count is known (fix-ups and notes included).
 */
export function spreadCommits(startMinute, endMinute, n, rng) {
  if (n <= 1) return [endMinute];
  const span = Math.max(endMinute - startMinute, n - 1);

  // random ascending fractions, then stretched onto the span
  const cuts = [];
  for (let i = 0; i < n - 2; i++) cuts.push(rng.next());
  cuts.sort((a, b) => a - b);

  const minutes = [startMinute];
  for (const c of cuts) minutes.push(Math.round(startMinute + c * span));
  minutes.push(endMinute);

  // enforce at least a minute between commits without ever exceeding the end
  for (let i = 1; i < minutes.length; i++) {
    if (minutes[i] <= minutes[i - 1]) minutes[i] = minutes[i - 1] + 1;
  }
  const overflow = minutes[minutes.length - 1] - endMinute;
  if (overflow > 0) for (let i = 0; i < minutes.length; i++) minutes[i] -= overflow;

  return minutes;
}

/**
 * Decide whether THIS probe run should do the work.
 *   before the end time  -> wait for a later probe (commits stay in the past)
 *   after it, within catchup -> go
 *   past last-chance with nothing committed today -> go anyway, protect the streak
 */
export function timingGate(plan, nowMinute, dayKey, config) {
  const t = config.timing;
  const lastChance = istToUtcMinutes(t.last_chance_ist);

  if (nowMinute >= lastChance) {
    return { go: true, reason: 'last-chance window' };
  }
  if (nowMinute < plan.endMinute) {
    return {
      go: false,
      reason: `too early - session lands at ${istClock(dayKey, plan.endMinute)}, now is ${istClock(dayKey, nowMinute)}`,
    };
  }
  if (nowMinute - plan.endMinute > t.max_catchup_minutes) {
    return { go: false, reason: 'window missed by more than the catch-up allowance' };
  }
  return { go: true, reason: 'in window' };
}
