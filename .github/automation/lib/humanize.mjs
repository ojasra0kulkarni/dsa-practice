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
 * slightly different habits - which is how one person's files actually drift.
 * The defaults lean hard toward terse, because verbose tidy code is the single
 * biggest giveaway that a model wrote it.
 */
const QUIRKS = [
  'you `typedef long long ll;` at the top out of habit, whether or not you use it',
  'you `#define pb push_back` at the top',
  'you leave one commented-out `// cout<<ans<<endl;` debug line from testing',
  'you declare `int n = arr.size();` on its own line before any loop, always',
  'you reuse `temp` for two unrelated things in the same function',
  'you write single-statement ifs on one line, like `if(a>mx) mx=a;`',
  'you use `auto` only for iterators, plain types everywhere else',
  'you leave one stray blank line at the end of the function body',
  'you write `vector<int>&arr` with no space around the ampersand',
  'you sometimes drop braces on a one-line for body',
];

const MOODS = [
  'in a hurry - correct, zero ceremony',
  'this pattern is familiar by now, so you barely think about it',
  'this one took a couple of tries, so the code is a bit patched-together',
  'straightforward problem, you typed it out in one go',
];

/** Two competing brace/spacing habits. Pick one per file and hold it. */
const SPACING = [
  {
    name: 'tight',
    desc: 'no spaces around operators or in for-headers: `for(int i=0;i<n;i++)`, `if(arr[i]>mx)`, `int mx=arr[0];`. Opening brace on the same line, sometimes omitted for one-liners.',
  },
  {
    name: 'tight',
    desc: 'no spaces around operators or in for-headers: `for(int i=0;i<n;i++)`, `if(arr[i]>mx)`, `int mx=arr[0];`. Opening brace on the same line, sometimes omitted for one-liners.',
  },
  {
    name: 'loose',
    desc: 'spaces around operators but still compact: `for (int i = 0; i < n; i++)`, `int mx = arr[0];`. Opening brace on the same line.',
  },
];

export function persona(rng) {
  return {
    quirks: rng.shuffle(QUIRKS).slice(0, rng.int(1, 2)),
    mood: rng.pick(MOODS),
    spacing: rng.pick(SPACING),
    // weighted hard toward none: a practice file is not documentation
    comments: rng.weighted({ none: 0.45, one: 0.35, two: 0.15, few: 0.05 }),
    includeMain: rng.chance(0.15),
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
