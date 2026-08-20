# Binary Search

## Implement Lower Bound

Just a standard binary search. If a value is greater than or equal to x, it's a potential answer, but we try to find an even smaller index. Otherwise, search right.

- If no element is found, the answer should be n (size of array), indicating insertion point.
- TC O(logN), SC O(1)

## Count occurrences of a number in a sorted array with duplicates

Used binary search twice: once to find the first occurrence of x, and once for the last. Then just subtract indices.

- If the number isn't in the array, first occurrence will be -1, so handle that.
- TC O(log n), SC O(1)

## Find minimum in Rotated Sorted Array

standard binary search, find the sorted part and update the minimum, then search in the other half to find the dip.

- forgetting to update ans with arr[l] in sorted left half
- TC O(logN), SC O(1)

## Single element in a Sorted Array

Binary search. Unique element breaks (even,odd) pair pattern. Adjust search range by checking mid's parity and value.

- Remember to handle edge cases for elements at the array ends separately.
- TC O(log N), SC O(1)
