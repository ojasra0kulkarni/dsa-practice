# Solve Problems on Arrays

## Longest subarray with given sum K (positives)

Sliding window technique. Expand right pointer, then shrink left if sum exceeds k. Update max length when sum matches k.

- Sum can overflow int if elements are large, use long long.
- TC O(N), SC O(1)

## Set Matrix Zeroes

Used the first row and column as markers for whether a row/column needs to be zeroed out. Had to use a separate boolean to track if the 0th column itself needs zeroing.

- Need a separate flag for the first column because mat[0][0] indicates status for both its row and column.
- TC O(N*M), SC O(1)

## Count subarrays with given sum

Keep track of prefix sums and their frequencies. For each sum, check if (sum - k) was seen before.

- Remember to initialize hashmap with 0:1 for subarrays starting from index 0.
- TC O(N), SC O(N)

## Count number of subarrays with given xor K

Iterate, maintain current XOR sum, and use a map to count previous XORs that would make the current XOR equal K. Remember to initialize map with {0:1} for subarrays starting at index 0.

- Initialize the hashmap with {0: 1} to account for subarrays starting from the beginning of the array.
- TC O(n), SC O(n)
