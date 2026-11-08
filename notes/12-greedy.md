# Greedy Algorithms

## N meetings in one room

Sort all meetings by their end times. Then iterate and pick any meeting whose start time is after the previously selected meeting's end time.

- The core trick is to sort meetings strictly by their end times.
- TC O(N log N), SC O(N)
