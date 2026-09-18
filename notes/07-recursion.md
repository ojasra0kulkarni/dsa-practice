# Recursion

## Generate all binary strings

just pick 0 then backtrack, then pick 1 and backtrack, it's a classic recursive pattern for generating combinations.

- don't forget to pop_back from the string after each recursive call to backtrack.
- TC O(n * 2^n), SC O(n * 2^n)

## Generate Parenthesis

Just keep track of open and close counts, adding open when possible and close only if there's an unmatched open. It's like building the string char by char.

- Always ensure closing parentheses don't outnumber open ones.
- TC O((4^n)/sqrt(n)) * O(n), SC O((4^n)/sqrt(n)) * O(n)
