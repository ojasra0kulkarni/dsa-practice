# Greedy Algorithms

## N meetings in one room

Sort all meetings by their end times. Then iterate and pick any meeting whose start time is after the previously selected meeting's end time.

- The core trick is to sort meetings strictly by their end times.
- TC O(N log N), SC O(N)

## Valid Parenthesis String

Keep track of the minimum and maximum possible open parentheses counts. Clip the minimum at zero and make sure the maximum never drops below zero. At the end, the minimum must be zero.

- Remember to clip `lo` at 0 at each step, and ensure `lo` is exactly 0 at the end.
- TC O(N), SC O(1)

## Jump Game

start from end, see if each position can reach the target, update target to reachable position.

- make sure logic works for n=1
- TC O(n), SC O(1)

## Shortest Job First

Just like OS scheduling, use a min-priority queue to pick the shortest job from available ones, and handle idle time.

- Remember to handle CPU idle time if no jobs are ready.
- TC O(N log N), SC O(N)
