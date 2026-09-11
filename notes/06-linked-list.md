# Linked List

## Middle of a Linked List

Just use a slow pointer and a fast pointer. Fast moves twice as fast as slow, so when fast reaches the end, slow will be in the middle.

- Remember to check fast and fast->next for nullptr to prevent segfaults.
- TC O(N), SC O(1)

## Reverse a Doubly Linked List

Just traverse the list, and for each node swap its next and prev pointers. Keep track of the next node before modifying.

- Remember to handle null head and single node cases, and update pointers carefully.
- TC O(n), SC O(1)

## Segregate odd and even nodes in Linked List

Make two separate lists, one for odd values and one for even values. Then just join them together.

- Remember to set the even list's tail next to nullptr to avoid cycles.
- TC O(N), SC O(1)
