# Sliding Window and Two Pointer

## Binary Subarray with Sum

This is a classic problem for counting subarrays. The trick is to count subarrays with sum AT MOST `goal`, then subtract subarrays with sum AT MOST `goal-1` to get exactly `goal`.

- The `cntAtMost` function must handle `goal-1` correctly if it results in a negative target.
- TC O(N), SC O(1)
