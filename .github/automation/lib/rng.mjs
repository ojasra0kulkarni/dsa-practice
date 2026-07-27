// Deterministic RNG. Every probe run on a given day must reach the SAME
// conclusion about when to commit and how much, otherwise the bot would
// fire at a different time on every cron tick. So: seed = hash(date + salt).

export function hashString(str) {
  let h = 2166136261 >>> 0;
  for (let i = 0; i < str.length; i++) {
    h ^= str.charCodeAt(i);
    h = Math.imul(h, 16777619) >>> 0;
  }
  return h >>> 0;
}

export function mulberry32(seed) {
  let a = seed >>> 0;
  return function () {
    a = (a + 0x6d2b79f5) >>> 0;
    let t = a;
    t = Math.imul(t ^ (t >>> 15), t | 1);
    t ^= t + Math.imul(t ^ (t >>> 7), t | 61);
    return ((t ^ (t >>> 14)) >>> 0) / 4294967296;
  };
}

/** Seeded generator with a few conveniences bolted on. */
export function makeRng(...parts) {
  const next = mulberry32(hashString(parts.join('|')));

  const api = {
    next,
    float: (lo, hi) => lo + next() * (hi - lo),
    int: (lo, hi) => Math.floor(lo + next() * (hi - lo + 1)),
    chance: (p) => next() < p,
    pick: (arr) => arr[Math.floor(next() * arr.length)],

    /** Sum of two uniforms -> triangular. Clusters values near the middle. */
    bell: (lo, hi) => lo + ((next() + next()) / 2) * (hi - lo),

    /** Triangular distribution with an explicit peak. */
    triangular: (lo, peak, hi) => {
      const u = next();
      const c = (peak - lo) / (hi - lo);
      return u < c
        ? lo + Math.sqrt(u * (hi - lo) * (peak - lo))
        : hi - Math.sqrt((1 - u) * (hi - lo) * (hi - peak));
    },

    /** weights: { "1": 0.35, "2": 0.4, ... } -> returns a key (as Number). */
    weighted: (weights) => {
      const entries = Object.entries(weights);
      const total = entries.reduce((s, [, w]) => s + w, 0);
      let r = next() * total;
      for (const [k, w] of entries) {
        r -= w;
        if (r <= 0) return Number(k);
      }
      return Number(entries[entries.length - 1][0]);
    },

    shuffle: (arr) => {
      const a = arr.slice();
      for (let i = a.length - 1; i > 0; i--) {
        const j = Math.floor(next() * (i + 1));
        [a[i], a[j]] = [a[j], a[i]];
      }
      return a;
    },

    /** Derive an independent stream from this one, tagged by name. */
    fork: (tag) => makeRng(String(next()), tag),
  };

  return api;
}
