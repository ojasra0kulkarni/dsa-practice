# Binary Search Trees

## Find K-th smallest and largest element in BST

Use inorder for smallest and reverse inorder for largest. Pass k by reference and decrement it to find the k-th node while traversing.

- Don't forget early exit in recursion after finding the answer.
- TC O(N), SC O(H)
