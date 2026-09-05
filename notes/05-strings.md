# Strings

## Implement Atoi

Just gotta go step by step: skip spaces, check sign, then build the number. The main thing is to handle integer overflow correctly at each digit. Need to remember INT_MIN magnitude is one larger than INT_MAX.

- The absolute value of INT_MIN is one greater than INT_MAX, so the overflow check for negative numbers is slightly different.
- TC O(N), SC O(1)

## Roman Number to Integer and vice versa

For Roman to Int, map chars to values and iterate, handling subtraction cases if the next char is larger. For Int to Roman, use a pre-sorted list of values/symbols and greedily subtract from the number.

- Remember the specific subtractive cases like IV, IX, CM for both conversions.
- TC O(L) where L is length of Roman numeral string, SC O(1)

## Sum of Beauty of all substrings

Iterate through all substrings using two nested loops. For each substring, maintain char frequencies and then find max/min frequencies to calculate beauty. Simple N^2.

- Min frequency needs to ignore characters that are not present in the current substring.
- TC O(N^2), SC O(1)
