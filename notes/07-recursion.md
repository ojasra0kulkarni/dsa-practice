# Recursion

## Generate all binary strings

just pick 0 then backtrack, then pick 1 and backtrack, it's a classic recursive pattern for generating combinations.

- don't forget to pop_back from the string after each recursive call to backtrack.
- TC O(n * 2^n), SC O(n * 2^n)
