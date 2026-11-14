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
