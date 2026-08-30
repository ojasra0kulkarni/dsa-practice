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

## Median of 2 sorted arrays

Binary search for the cut point in the shorter array. Figure out the corresponding cut in the other array. Check if the elements on either side of the cuts are correctly ordered. Adjust binary search range based on comparisons.

- Remember to use INT_MIN/INT_MAX when a partition cut is at the very beginning or very end of an array.
- TC O(log(min(n1, n2))), SC O(1)

## Find Peak Element in 2D matrix

Binary search on columns. For the middle column, find the global maximum element in that column. If it's greater than both its horizontal neighbors, it's a peak. Otherwise, move the search towards the direction of the greater neighbor.

- Handle boundary conditions for left/right neighbors in the first/last column by assigning a very small value like -1 since elements are positive.
- TC O(N log M), SC O(1)

## Painter's Partition

Binary search on the possible range of answers. Check if a given max sum is achievable with k painters and adjust search range.

- The lower bound for binary search should be the max element, and a single board can be larger than mid.
- TC O(N log S) where S is the sum of all board lengths, SC O(1)

## Find the row with maximum number of 1s

Start from top right corner. If it's a 1, that's a candidate row; move left. If it's a 0, move down to the next row.

- Iterating each row with a simple count or binary search is slower than the two-pointer approach.
- TC O(N + M), SC O(1)

## Matrix Median

standard binary search on answer problem. in each step, use upper_bound on each row to count elements less than or equal to mid. adjust search space based on total count.

- ensure the target count for the median (req) is correctly calculated as (N*M)/2 + 1 for 1-based indexing of the median.
- TC O(N * log M * log(MAX_VAL)), SC O(1)
