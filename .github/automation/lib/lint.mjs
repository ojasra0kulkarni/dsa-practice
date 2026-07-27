// A prompt asks nicely; this enforces. Generated code is scanned for the
// handful of things that make a file read as machine-written, and anything
// that trips a rule gets sent back for another attempt.

// snake_case identifiers that belong to the standard library, not the author
const STDLIB = new Set([
  'push_back', 'pop_back', 'emplace_back', 'max_element', 'min_element',
  'lower_bound', 'upper_bound', 'unordered_map', 'unordered_set', 'priority_queue',
  'make_pair', 'back_inserter', 'to_string', 'size_t', 'long_long', 'bits_stdc',
  'begin', 'end', 'rbegin', 'rend', 'front', 'back', 'get_line', 'setprecision',
  'next_permutation', 'prev_permutation', 'binary_search', 'is_sorted', 'stable_sort',
]);

// short names that are fine even though they read as words
const OK_NAMES = new Set(['nums', 'arr', 'ans', 'temp', 'tmp', 'curr', 'prev', 'node', 'head', 'root', 'res', 'idx', 'cnt', 'sum', 'vis', 'adj', 'dist']);

const BANNED_PHRASES = [
  // persona leakage - the model describing its own instructions
  /\b(student|persona|confident|modern|as a beginner|human-?like)\b/i,
  // documentation voice
  /\/\/\s*(function|method) to /i,
  /\/\/\s*initialize (the|our|a) /i,
  /\/\/\s*traverse (the|through) /i,
  /\/\/\s*return the (result|answer|final)/i,
  /\/\/\s*(step|approach) \d+[:.]/i,
  /@param|@return|@brief/,
  /\/\*\*/,
  /[=\-*]{6,}/,
];

/**
 * Identifier checks must not see comment prose or string literals, or a
 * perfectly good `// monotonic stack` gets flagged as a long variable name.
 */
function stripProse(code) {
  return code
    .replace(/\/\*[\s\S]*?\*\//g, ' ')
    .replace(/\/\/[^\n]*/g, ' ')
    .replace(/"(?:[^"\\]|\\.)*"/g, '""');
}

export function findTells(code) {
  const tells = [];
  const lines = code.split('\n');
  const src = stripProse(code);

  // --- 1. long identifiers -------------------------------------------------
  // A camelCase name followed by "(" is a function - LeetCode signatures are
  // camelCase by mandate (maxSubArray, twoSum), so those are never the author's
  // choice. Everything else camelCase is a variable the author named badly.
  const camel = [
    ...new Set(
      [...src.matchAll(/\b([a-z]+[A-Z][a-zA-Z0-9]*)\b(\s*\()?/g)]
        .filter((m) => !m[2])
        .map((m) => m[1])
    ),
  ];
  if (camel.length) {
    tells.push(
      `camelCase variable names: ${camel.slice(0, 6).join(', ')}. Rename to 1-3 char names (mx, cnt, ans, i, j, tmp).`
    );
  }

  const snake = [
    ...new Set(
      [...src.matchAll(/\b([a-z]{2,}_[a-z]{2,}[a-z0-9_]*)\b(\s*\()?/g)]
        .filter((m) => !m[2] && !STDLIB.has(m[1]))
        .map((m) => m[1])
    ),
  ];
  if (snake.length) {
    tells.push(
      `multi-word snake_case variable names: ${snake.slice(0, 6).join(', ')}. Rename to 1-3 char names.`
    );
  }

  // long single-word names the author invented
  const longWords = [
    ...new Set(
      [...src.matchAll(/\b([a-z]{8,})\b(\s*\()?/g)]
        .filter((m) => !m[2] && !OK_NAMES.has(m[1]) && !STDLIB.has(m[1]))
        .map((m) => m[1])
    ),
  ].filter((w) => !/^(include|namespace|using|return|vector|string|unordered|priority|continue|iostream|algorithm|endl|nullptr)$/.test(w));
  if (longWords.length) {
    tells.push(`over-long variable names: ${longWords.slice(0, 6).join(', ')}. Shorten them.`);
  }

  // --- 2. comment density --------------------------------------------------
  const commentLines = lines.filter((l) => l.trim().startsWith('//')).length;
  const inlineComments = lines.filter((l) => !l.trim().startsWith('//') && l.includes('//')).length;
  const totalComments = commentLines + inlineComments;
  const codeLines = lines.filter((l) => l.trim() && !l.trim().startsWith('//')).length;

  if (totalComments > 4) {
    tells.push(`${totalComments} comments is far too many. Cut to at most 2 short ones.`);
  }
  if (codeLines > 0 && totalComments / codeLines > 0.3) {
    tells.push('roughly one comment per line. Delete almost all of them.');
  }
  const longComment = lines.find((l) => l.trim().startsWith('//') && l.trim().length > 70);
  if (longComment) {
    tells.push(`this comment is an essay: "${longComment.trim().slice(0, 60)}...". Max 8 words, or delete it.`);
  }

  // --- 3. banned phrases ---------------------------------------------------
  for (const pat of BANNED_PHRASES) {
    const hit = code.match(pat);
    if (hit) tells.push(`remove this - it reads as generated: "${hit[0].trim().slice(0, 60)}"`);
  }

  // --- 4. bloated main() ---------------------------------------------------
  const mainStart = code.indexOf('int main(');
  if (mainStart !== -1) {
    const main = code.slice(mainStart);
    const couts = (main.match(/cout\s*<</g) || []).length;
    if (couts > 2) {
      tells.push(`main() prints ${couts} test cases. Keep exactly one, with no descriptive label text.`);
    }
    if (/cout\s*<<\s*"[^"]{15,}/.test(main)) {
      tells.push('main() prints labelled strings like "Second largest in {...}:". Print the bare value only.');
    }
  }

  return tells;
}
