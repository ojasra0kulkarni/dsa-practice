# Heaps

## Kth smallest element in an array

I'll use a max-heap of size k. I push elements and if the heap gets too big, I pop the largest, which ensures only the k smallest elements remain, with the kth smallest at the top.

- It's easy to confuse max-heap for Kth smallest vs. min-heap for Kth largest; remember which one to use.
- TC O(N log K), SC O(K)
