import { execFileSync } from 'node:child_process';

export function makeGit(cwd, dryRun = false) {
  const MUTATING = new Set(['commit', 'push', 'add']);
  const run = (args, env = {}) => {
    if (dryRun && MUTATING.has(args[0])) {
      console.log(`  [dry-run] git ${args.join(' ')}`);
      return '';
    }
    return execFileSync('git', args, {
      cwd,
      encoding: 'utf8',
      env: { ...process.env, ...env },
      stdio: ['ignore', 'pipe', 'pipe'],
    }).trim();
  };

  return {
    run,
    add: (paths) => run(['add', '--', ...paths]),

    /**
     * The timestamp is the whole point. Author AND committer are set to the
     * humanized local time so the commit carries a +05:30 offset instead of
     * the runner's UTC.
     */
    commit(message, isoDate) {
      return run(['commit', '-m', message], {
        GIT_AUTHOR_DATE: isoDate,
        GIT_COMMITTER_DATE: isoDate,
      });
    },

    /** Fold newly staged files into the previous commit, keeping its message and time. */
    amend(isoDate) {
      return run(['commit', '--amend', '--no-edit'], {
        GIT_AUTHOR_DATE: isoDate,
        GIT_COMMITTER_DATE: isoDate,
      });
    },

    hasStagedChanges() {
      try {
        execFileSync('git', ['diff', '--cached', '--quiet'], { cwd, stdio: 'ignore' });
        return false;
      } catch {
        return true;
      }
    },

    push(branch) {
      for (let attempt = 1; attempt <= 3; attempt++) {
        try {
          return run(['push', 'origin', `HEAD:${branch}`]);
        } catch (err) {
          console.log(`  ! push attempt ${attempt} failed: ${String(err.message).slice(0, 200)}`);
          if (attempt === 3) throw err;
          try {
            run(['pull', '--rebase', 'origin', branch]);
          } catch {
            /* nothing to rebase onto yet */
          }
        }
      }
    },

    currentBranch() {
      try {
        return run(['rev-parse', '--abbrev-ref', 'HEAD']) || 'main';
      } catch {
        return 'main';
      }
    },
  };
}
