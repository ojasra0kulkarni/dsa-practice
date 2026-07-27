const ENDPOINT = 'https://generativelanguage.googleapis.com/v1beta/models';

const RESPONSE_SCHEMA = {
  type: 'OBJECT',
  properties: {
    code: { type: 'STRING', description: 'The complete C++ file contents. No markdown fences.' },
    approach_tag: { type: 'STRING', description: 'Two or three words, e.g. "two pointer", "hashmap", "binary search on answer".' },
    approach_note: { type: 'STRING', description: 'One or two casual sentences, as a student would write in their own notes.' },
    time_complexity: { type: 'STRING' },
    space_complexity: { type: 'STRING' },
    gotcha: { type: 'STRING', description: 'One short line about the edge case or trick that is easy to miss.' },
  },
  required: ['code', 'approach_tag', 'approach_note', 'time_complexity', 'space_complexity', 'gotcha'],
};

function buildPrompt(problem, persona, cfg) {
  const revisionNote = problem.revision
    ? `\nTHIS IS A REVISIT (pass ${problem.revision + 1}). The student already solved this once and is
  coming back to it during revision. Write a DIFFERENT approach than the most obvious one -
  e.g. the space-optimised version, the iterative version instead of recursive, or a cleaner
  rewrite. Add one short comment acknowledging the earlier attempt, in passing, not as a banner.\n`
    : '';

  return `You are writing a C++ solution file for a personal DSA practice repository.
${revisionNote}

The repo belongs to a third-year B.Tech CSE student in India who is working through
Striver's A2Z DSA sheet for placement prep. You are writing AS that student, in their
editor, at the moment they solved it. This is a practice file, not a library and not a
teaching resource.

PROBLEM
  Step ${problem.step} - ${problem.stepTitle}
  Section: ${problem.section}
  Problem: ${problem.name}

TODAY'S WRITING STYLE (follow these, they vary day to day on purpose)
  - Mood: ${persona.mood}
  - Comment density: ${persona.verbosity}
${persona.quirks.map((q) => `  - Habit: ${q}`).join('\n')}
${persona.includeMain ? '  - Include a small main() at the bottom that runs one hardcoded test case.' : '  - Do NOT include a main() function; just the solution class/function.'}

HARD RULES
  - Output the file contents only, in the "code" field. No markdown fences, no backticks.
  - Start with #include <bits/stdc++.h> and using namespace std; (that is what this student does).
  - The solution must be genuinely correct and actually compile. Correctness is not negotiable.
  - Use the standard LeetCode/GFG signature for this problem where one exists
    (e.g. class Solution { public: ... };). If the problem has no standard judge signature,
    write a clean standalone function.
  - Comments must sound like a student talking to themselves: short, lowercase-ish,
    sometimes fragments. Never write documentation-style comment blocks.
  - Do NOT write a header banner with the problem link, difficulty, date, or author.
    At most one short line naming the problem, and only sometimes.
  - Do NOT use emoji. Do NOT use section-divider comments made of ===== or -----.
  - Do NOT explain what a for loop does. Explain only the non-obvious step.
  - Total comment lines should be roughly ${persona.verbosity === 'sparse' ? '0 to 3' : persona.verbosity === 'chatty' ? '5 to 9' : '2 to 5'}.

Write the file now.`;
}

function extractJson(data) {
  const parts = data?.candidates?.[0]?.content?.parts || [];
  const text = parts.map((p) => p.text || '').join('').trim();
  if (!text) throw new Error('empty response from model');
  try {
    return JSON.parse(text);
  } catch {
    const m = text.match(/\{[\s\S]*\}/);
    if (!m) throw new Error(`unparseable response: ${text.slice(0, 200)}`);
    return JSON.parse(m[0]);
  }
}

function stripFences(code) {
  return code
    .replace(/^\s*```(?:cpp|c\+\+|)\s*\n/i, '')
    .replace(/\n```\s*$/, '')
    .trim();
}

const sleep = (ms) => new Promise((r) => setTimeout(r, ms));

export async function generateSolution(problem, persona, cfg, apiKey) {
  const prompt = buildPrompt(problem, persona, cfg);
  const body = {
    contents: [{ role: 'user', parts: [{ text: prompt }] }],
    generationConfig: {
      temperature: cfg.temperature,
      topP: cfg.top_p,
      responseMimeType: 'application/json',
      responseSchema: RESPONSE_SCHEMA,
    },
  };

  let lastError;
  for (const model of cfg.models) {
    for (let attempt = 1; attempt <= cfg.max_retries; attempt++) {
      try {
        const res = await fetch(`${ENDPOINT}/${model}:generateContent`, {
          method: 'POST',
          headers: { 'content-type': 'application/json', 'x-goog-api-key': apiKey },
          body: JSON.stringify(body),
        });

        if (!res.ok) {
          const detail = await res.text();
          throw new Error(`${model} HTTP ${res.status}: ${detail.slice(0, 300)}`);
        }

        const parsed = extractJson(await res.json());
        parsed.code = stripFences(parsed.code || '');
        if (parsed.code.length < 40) throw new Error('response too short to be a real solution');
        if (!parsed.code.endsWith('\n')) parsed.code += '\n';
        return parsed;
      } catch (err) {
        lastError = err;
        console.log(`  ! ${model} attempt ${attempt} failed: ${err.message}`);
        if (attempt < cfg.max_retries) await sleep(cfg.retry_backoff_ms * attempt);
      }
    }
  }
  throw lastError;
}
