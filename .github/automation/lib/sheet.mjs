export function slugify(name) {
  return name
    .toLowerCase()
    .replace(/\+/g, ' plus ')
    .replace(/['’]/g, '') // kadane's -> kadanes, not kadane-s
    .replace(/[^a-z0-9]+/g, '-')
    .replace(/^-+|-+$/g, '')
    .slice(0, 70);
}

/** Flatten the sheet into an ordered list with stable global indices. */
export function flatten(sheet, startStep = 1) {
  const out = [];
  for (const step of sheet.steps) {
    if (step.id < startStep) continue;
    for (const section of step.sections) {
      for (const name of section.problems) {
        out.push({
          index: out.length,
          name,
          step: step.id,
          stepTitle: step.title,
          stepSlug: step.slug,
          section: section.name,
          // "04-binary-search" -> "binary search"; reads better in a commit
          // subject than the full step title ("Solve Problems on Arrays").
          topic: step.slug.replace(/^\d+-/, '').replace(/-/g, ' '),
          slug: slugify(name),
        });
      }
    }
  }
  return out;
}

/**
 * Pick the next `count` problems. Mostly straight down the sheet, but a
 * human occasionally skips ahead to something that looks interesting and
 * circles back later - so do that a fraction of the time.
 */
export function pickNext(all, done, count, rng, content, revisits = {}) {
  const doneSet = new Set(done);
  const picked = [];
  let cursor = 0;

  while (picked.length < count) {
    while (cursor < all.length && (doneSet.has(cursor) || picked.some((p) => p.index === cursor))) {
      cursor++;
    }

    // Sheet exhausted: go back over old problems with a different approach.
    // Least-revisited first, so it works through the whole sheet again.
    if (cursor >= all.length) {
      const pool = all
        .filter((p) => !picked.some((q) => q.index === p.index))
        .sort((a, b) => (revisits[a.index] || 0) - (revisits[b.index] || 0));
      if (!pool.length) break;
      const band = pool.slice(0, Math.max(1, Math.min(15, pool.length)));
      const chosen = rng.pick(band);
      picked.push({ ...chosen, revision: (revisits[chosen.index] || 0) + 1 });
      continue;
    }

    let choice = cursor;
    if (rng.chance(content.out_of_order_chance)) {
      const window = [];
      for (let i = cursor; i < Math.min(all.length, cursor + content.out_of_order_window); i++) {
        if (!doneSet.has(i) && !picked.some((p) => p.index === i)) window.push(i);
      }
      if (window.length) choice = rng.pick(window);
    }

    picked.push(all[choice]);
    doneSet.add(choice);
  }

  return picked;
}

export function progressByStep(sheet, all, done) {
  const doneSet = new Set(done);
  const byStep = new Map();
  for (const p of all) {
    if (!byStep.has(p.step)) {
      byStep.set(p.step, { id: p.step, title: p.stepTitle, slug: p.stepSlug, total: 0, done: 0 });
    }
    const s = byStep.get(p.step);
    s.total++;
    if (doneSet.has(p.index)) s.done++;
  }
  return [...byStep.values()].sort((a, b) => a.id - b.id);
}
