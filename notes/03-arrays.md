# Solve Problems on Arrays

## Longest subarray with given sum K (positives)

Sliding window technique. Expand right pointer, then shrink left if sum exceeds k. Update max length when sum matches k.

- Sum can overflow int if elements are large, use long long.
- TC O(N), SC O(1)
