// Everything internally is "minutes since midnight UTC" on a given UTC date.
// The whole active window (13:00 - 23:52 IST) lives inside a single UTC date,
// which keeps the arithmetic boring on purpose.

export const IST_OFFSET_MIN = 330;

export function parseClock(hhmm) {
  const [h, m] = hhmm.split(':').map(Number);
  return h * 60 + m;
}

export function istToUtcMinutes(hhmm) {
  return parseClock(hhmm) - IST_OFFSET_MIN;
}

export function utcDateKey(date) {
  return date.toISOString().slice(0, 10);
}

export function utcMinutesNow(date) {
  return date.getUTCHours() * 60 + date.getUTCMinutes();
}

/** UTC date key + minute offset -> real Date. */
export function toDate(dayKey, utcMinute, seconds = 0) {
  return new Date(Date.parse(`${dayKey}T00:00:00Z`) + utcMinute * 60000 + seconds * 1000);
}

/**
 * Format a Date as a git-friendly timestamp carrying a real local offset,
 * e.g. 2026-07-27T19:42:11+05:30.
 *
 * This matters: a runner in UTC would otherwise stamp every commit +0000,
 * which reads as "this was not written on a laptop in India".
 */
export function gitDate(date, offsetMinutes = IST_OFFSET_MIN, offsetLabel = '+05:30') {
  const shifted = new Date(date.getTime() + offsetMinutes * 60000);
  const pad = (n) => String(n).padStart(2, '0');
  return (
    `${shifted.getUTCFullYear()}-${pad(shifted.getUTCMonth() + 1)}-${pad(shifted.getUTCDate())}` +
    `T${pad(shifted.getUTCHours())}:${pad(shifted.getUTCMinutes())}:${pad(shifted.getUTCSeconds())}` +
    offsetLabel
  );
}

/** Human-readable IST clock for logs. */
export function istClock(dayKey, utcMinute) {
  const total = ((utcMinute + IST_OFFSET_MIN) % 1440 + 1440) % 1440;
  const h = Math.floor(total / 60);
  const m = total % 60;
  return `${String(h).padStart(2, '0')}:${String(m).padStart(2, '0')} IST`;
}

/** 0 = Sunday. Uses the IST calendar day, which is what a human would feel. */
export function istWeekday(dayKey, utcMinute) {
  return toDate(dayKey, utcMinute + IST_OFFSET_MIN).getUTCDay();
}
