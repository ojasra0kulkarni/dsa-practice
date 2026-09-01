# Strings

## Implement Atoi

Just gotta go step by step: skip spaces, check sign, then build the number. The main thing is to handle integer overflow correctly at each digit. Need to remember INT_MIN magnitude is one larger than INT_MAX.

- The absolute value of INT_MIN is one greater than INT_MAX, so the overflow check for negative numbers is slightly different.
- TC O(N), SC O(1)
