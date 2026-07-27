import { progressByStep } from './sheet.mjs';

function bar(done, total, width = 18) {
  const filled = total === 0 ? 0 : Math.round((done / total) * width);
  return '█'.repeat(filled) + '░'.repeat(width - filled);
}

export function renderReadme(sheet, all, state, config) {
  const steps = progressByStep(sheet, all, state.done);
  const total = all.length;
  const done = state.done.length;
  const pct = total ? ((done / total) * 100).toFixed(1) : '0.0';

  const rows = steps
    .map(
      (s) =>
        `| ${String(s.id).padStart(2, '0')} | ${s.title} | ${s.done}/${s.total} | \`${bar(s.done, s.total)}\` |`
    )
    .join('\n');

  const recent = (state.recent || [])
    .slice(-12)
    .reverse()
    .map((r) => `- \`${r.date}\` — ${r.name}`)
    .join('\n');

  return `# DSA Practice

Working through [Striver's A2Z DSA Sheet](${sheet.source}) in C++.
One folder per step, one file per problem. Nothing fancy — just keeping myself honest.

**${done} / ${total} solved (${pct}%)**

## Progress by step

| # | Step | Solved | |
|---|------|--------|---|
${rows}

## Recently solved

${recent || '_nothing yet_'}

## Layout

\`\`\`
solutions/<step>/<problem>.cpp
notes/<step>.md
\`\`\`

Complexities are noted at the top or bottom of each file, depending on my mood that day.
`;
}
