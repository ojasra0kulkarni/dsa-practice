# Stacks and Queues

## Implement Stack using Queue

To make pop/top O(1), I made push costly. On push, add new element to temp, then move all existing elements from main queue to temp, then swap queues. This ensures the newest element is always at the front.

- Ensuring the newest element is always at the front of the main queue after each push.
- TC push O(N), pop O(1), top O(1), empty O(1), SC O(N)
