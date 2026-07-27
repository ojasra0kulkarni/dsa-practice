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

  const commentBudget = {
    none: 'ZERO comments. Not one. The code stands alone.',
    one: 'Exactly ONE short comment, on the single least obvious line. Nothing else.',
    two: 'At most TWO short comments, total.',
    few: 'At most THREE short comments, total.',
  }[persona.comments];

  return `Write a C++ file the way a real student writes it in their own practice repo.
${revisionNote}
The author is a third-year B.Tech CSE student in India grinding Striver's A2Z sheet for
placements. They write like a competitive programmer: fast, terse, unpolished. This file
is scratch work they will never show anyone. It is NOT a tutorial, NOT documentation,
NOT a portfolio piece.

PROBLEM
  Step ${problem.step} - ${problem.stepTitle} (${problem.section})
  ${problem.name}

THE #1 RULE: SHORT VARIABLE NAMES
Competitive programmers do not write descriptive names. They write one to three
characters. Use these and nothing longer:
  n, m, i, j, k, x, y, a, b, arr, v, s, ans, mx, mn, cnt, sum, temp, tmp, idx,
  l, r, lo, hi, mid, st, en, mp, st, pq, dp, vis, adj, res, curr, prev, node, head
BANNED - these instantly read as machine-written:
  maxElement, currentIndex, resultArray, numsSize, leftPointer, tempVariable,
  maximumValue, isFound, countOfElements, previousNode, currentSum, targetSum
If you catch yourself writing two words joined together, cut it to an abbreviation.

COMMENTS
  ${commentBudget}
  A comment, if any, is lowercase, under 8 words, no full stop, and explains only the
  ONE thing that is not obvious from reading the code. Fragments are fine.
  Good: // two pointer from both ends
  Good: // mid overflow
  Good: // 1-indexed here
  BANNED: "// Function to find the maximum element in the array"
  BANNED: "// Initialize variables"  "// Traverse the array"  "// Return the result"
  BANNED: any comment restating what the next line literally does.
  BANNED: header banners, ====== dividers, @param/@return, /** */ doc blocks.

SPACING
  ${persona.spacing.desc}
  Hold this style consistently through the whole file.

TODAY'S HABITS
  - ${persona.mood}
${persona.quirks.map((q) => `  - ${q}`).join('\n')}
${persona.includeMain ? '  - Add a tiny main() at the bottom with one hardcoded test case.' : '  - No main(). Just the solution class/function.'}

STRUCTURE
  - Open with #include <bits/stdc++.h> then using namespace std;
  - Use the standard judge signature where one exists (class Solution { public: ... };).
    Otherwise a plain standalone function.
  - No complexity analysis block. If you mention complexity at all, it is one terse
    trailing line like "// O(n) time O(1) space" and usually you skip even that.
  - Do not add extra blank lines to make it look organised.

CORRECTNESS IS NOT NEGOTIABLE. Terse does not mean wrong - it must compile and be right.

Here is the exact difference you are aiming for.

WRONG - obviously machine-written:
class Solution {
public:
    // Function to find the largest element in the array
    int largestElement(vector<int>& nums) {
        // Initialize the maximum with the first element
        int maxElement = nums[0];
        // Traverse the array to find the maximum
        for (int index = 1; index < nums.size(); index++) {
            if (nums[index] > maxElement) {
                maxElement = nums[index];
            }
        }
        // Return the result
        return maxElement;
    }
};

RIGHT - how the student actually writes it:
class Solution {
public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        int mx = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>mx) mx=arr[i];
        }
        return mx;
    }
};

Output the file contents only in the "code" field. No markdown fences, no backticks.`;
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
