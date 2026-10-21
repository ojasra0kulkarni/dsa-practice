# Stacks and Queues

## Implement Stack using Queue

To make pop/top O(1), I made push costly. On push, add new element to temp, then move all existing elements from main queue to temp, then swap queues. This ensures the newest element is always at the front.

- Ensuring the newest element is always at the front of the main queue after each push.
- TC push O(N), pop O(1), top O(1), empty O(1), SC O(N)

## Check for balanced parenthesis

Put opening brackets onto the stack. For closing brackets, pop and check if it matches. If stack empty or mismatch, it's invalid. Finally, stack must be empty.

- Empty stack check for closing brackets, and final empty check for remaining opening brackets.
- TC O(N), SC O(N)

## Infix to Postfix Conversion using Stack

Just iterate through the expression and use a stack to manage operators based on their precedence. Handle parentheses as special cases.

- Make sure to pop remaining operators from the stack at the very end.
- TC O(N), SC O(N)

## Postfix to Prefix Conversion

Iterate through the expression, push operands to stack. When an operator comes, pop two operands, form "operator + op2 + op1" (important order!) and push back.

- Remember the correct order of operands when popping from the stack for prefix: it's `operator + second_popped + first_popped`.
- TC O(N), SC O(N)

## Next Smaller Element

Iterate from right to left and use a stack. Pop elements from stack that are not smaller than current element.

- Iterate from right to left for the 'next' (to the right) smaller element.
- TC O(n), SC O(n)
