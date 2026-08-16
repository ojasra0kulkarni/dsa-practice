# Binary Search

## Implement Lower Bound

Just a standard binary search. If a value is greater than or equal to x, it's a potential answer, but we try to find an even smaller index. Otherwise, search right.

- If no element is found, the answer should be n (size of array), indicating insertion point.
- TC O(logN), SC O(1)
