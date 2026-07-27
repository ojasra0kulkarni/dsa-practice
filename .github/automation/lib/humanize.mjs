// Everything in here exists to sand off the edges that make generated
// repos look generated: identical commit subjects, perfect capitalisation,
// the same file header on all 400 files.

const MESSAGE_TEMPLATES = [
  '{name}',
  '{name_lower}',
  'solved {name_lower}',
  '{name} - {approach}',
  '{topic}: {name}',
  '{name} ({approach})',
  'add {name_lower}',
  '{name_lower} done',
  'day {day} - {name_lower}',
  '{name} | {tc}',
  'practice: {name_lower}',
  '{name_lower} (finally)',
];

const FIX_TEMPLATES = [
  'fix edge case in {name_lower}',
  'handle empty input - {name_lower}',
  'minor cleanup',
  'fix overflow in {name_lower}',
  'forgot to note complexity',
  'small refactor',
  'oops, wrong variable name',
  'update complexity comment',
];

const NOTE_TEMPLATES = [
  'notes for {topic}',
  'add notes',
  'update notes',
  '{topic} notes',
  'jotting down the pattern',
];

const README_TEMPLATES = ['update progress', 'update readme', 'progress', 'readme', 'update tracker'];

// Rare, deliberate, and small. Overdo this and it reads as noise.
const TYPO_MAP = [
  [/\bthe\b/, 'teh'],
  [/\bwith\b/, 'wiht'],
  [/\barray\b/, 'aray'],
  [/\bsolution\b/, 'soltuion'],
];

function applyTypo(msg, rng) {
  if (!rng.chance(0.04)) return msg;
  const [pat, rep] = rng.pick(TYPO_MAP);
  return msg.replace(pat, rep);
}

const REVISION_TEMPLATES = [
  'revision: {name_lower}',
  '{name_lower} - {approach} this time',
  'redo {name_lower}',
  '{name} again, {approach}',
  'revisiting {name_lower}',
  '{name_lower} v2',
];

/** Nobody uses the same phrasing twice in one sitting. */
function pickUnused(pool, rng, used) {
  for (let i = 0; i < 6; i++) {
    const t = rng.pick(pool);
    if (!used.has(t)) {
      used.add(t);
      return t;
    }
  }
  return rng.pick(pool);
}

export function commitMessage(problem, meta, rng, dayNumber, used = new Set()) {
  const tpl = pickUnused(problem.revision ? REVISION_TEMPLATES : MESSAGE_TEMPLATES, rng, used);
  let msg = tpl
    .replace('{name}', problem.name)
    .replace('{name_lower}', problem.name.toLowerCase())
    .replace('{topic}', problem.topic)
    .replace('{approach}', (meta.approach_tag || 'optimal').toLowerCase())
    .replace('{tc}', meta.time_complexity || 'O(n)')
    .replace('{day}', String(dayNumber));

  // most people type commit subjects in lowercase, some don't
  if (rng.chance(0.25)) msg = msg.charAt(0).toUpperCase() + msg.slice(1);
  return applyTypo(msg, rng);
}

export function fixMessage(problem, rng) {
  return rng
    .pick(FIX_TEMPLATES)
    .replace('{name_lower}', problem.name.toLowerCase())
    .replace('{name}', problem.name);
}

export function notesMessage(problem, rng) {
  return rng.pick(NOTE_TEMPLATES).replace('{topic}', problem.topic);
}

export function readmeMessage(rng) {
  return rng.pick(README_TEMPLATES);
}

/**
 * A per-day style persona handed to the model. Same author, different day,
 * different mood - which is exactly how a real person's files drift.
 */
const QUIRKS = [
  'you use a `typedef long long ll;` at the top out of habit',
  'you name your loop counters i, j, k and nothing else',
  'you leave one commented-out `// cout << ... ` debug line you used while testing',
  'you write the brute force idea as a one-line comment above the optimal one',
  'you use `#define pb push_back` even when you only call it twice',
  'you put the complexity comment at the very bottom of the file',
  'you put the complexity comment right above the function',
  'you use `vector<int>&nums` with no space after the ampersand',
  'you write slightly terse comments, lowercase, no full stops',
  'you occasionally write a comment that is just `// tricky part`',
  'you prefer `int n = nums.size();` on its own line before any loop',
  'you write a tiny `main()` at the bottom to test with one hardcoded case',
  'you skip comments almost entirely on problems you found easy',
  'you use `auto` for iterators but plain types everywhere else',
];

const MOODS = [
  'in a hurry, so the code is correct but sparse on comments',
  'relaxed, so you explain your reasoning in two or three short comments',
  'slightly frustrated - this one took a few attempts',
  'confident, this pattern is familiar by now',
  'careful, because you got the edge cases wrong the first time',
];

export function persona(rng) {
  const picks = rng.shuffle(QUIRKS).slice(0, rng.int(2, 3));
  return {
    quirks: picks,
    mood: rng.pick(MOODS),
    verbosity: rng.pick(['sparse', 'normal', 'normal', 'chatty']),
    includeMain: rng.chance(0.22),
  };
}

/** Occasional trailing edit that makes a file look revisited, not dropped. */
export function makeFollowUpEdit(code, problem, rng) {
  const options = [
    () => code.replace(/\s*$/, '\n\n// edge case: empty input handled above\n'),
    () => code.replace(/\s*$/, `\n\n// note to self: revisit the ${rng.pick(['two pointer', 'hashmap', 'binary search', 'greedy'])} variant\n`),
    () => code.replace(/\s*$/, '\n\n// TODO: try the O(1) space version\n'),
    () => code.replace(/\s*$/, `\n// ^ submitted, accepted\n`),
  ];
  return rng.pick(options)();
}
