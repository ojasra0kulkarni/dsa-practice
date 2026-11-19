# Binary Trees

## Binary Tree Representation in C++

This is the basic way to set up a binary tree node, used recursion for a simple traversal to check it.

- always handle null pointers for children
- TC O(N), SC O(H)

## Preorder Traversal of Binary Tree

Just follow the definition: root, then left subtree, then right subtree. Base case is a null node.

- Remember the base case for recursion, if node is null just return.
- TC O(N), SC O(H)

## Inorder Traversal of Binary Tree

standard recursive way to do inorder, left-root-right

- handle empty tree (null root)
- TC O(N), SC O(H)

## Postorder Traversal of Binary Tree

Iterative postorder is a bit tricky, ended up using two stacks to manage the order. One stack helps reverse processing.

- Remember to push left child then right child onto the first stack.
- TC O(N), SC O(N)

## Level order Traversal

Standard BFS with a queue. Remember to grab the queue size each iteration to split levels.

- Need to process nodes for current level by iterating 'sz' times before adding children, not just popping all.
- TC O(N), SC O(N)

## Iterative Inorder Traversal of Binary Tree

Use a stack to simulate recursion. Keep pushing left children onto the stack until null, then pop, process, and go right.

- The loop condition needs to check both current node and stack to handle all cases.
- TC O(N), SC O(H)

## Postorder Traversal of Binary Tree using 1 stack

Postorder with one stack is tricky; need to use a 'prev' pointer to know if the right child has been processed already.

- Remember the 'prev' pointer to prevent re-visiting the right child indefinitely.
- TC O(N), SC O(H)

## Preorder Inorder and Postorder Traversal in one Traversal

Use a stack to manage nodes and their visit states. Bump the state and re-push the node; push children with state 1 to process them first.

- Order of pushes to stack matters to maintain correct traversal sequence.
- TC O(N), SC O(N)

## Check if the Binary Tree is height-balanced or not

A recursive DFS function checks height and balance status from bottom up. If any subtree is unbalanced, it flags it up.

- Return -1 from the recursive function to signal an unbalanced subtree.
- TC O(N), SC O(H)
