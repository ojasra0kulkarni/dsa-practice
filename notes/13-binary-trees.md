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

## Check if two trees are identical or not

Simple recursion, just check if current nodes match and then recurse on their left and right children. Handle nulls carefully.

- Missing any of the null checks can lead to segfaults or incorrect results.
- TC O(min(N1, N2)), SC O(H)

## Bottom View of Binary Tree

Used BFS to traverse level by level. Map stores horizontal distance to node value; updating it on each visit ensures the deepest node for that distance is kept.

- Using a map automatically sorts horizontal distances and overwrites ensure bottom-most node.
- TC O(N log K), SC O(N)

## Construct Binary Tree from inorder and preorder

Just recursively build left and right subtrees. Map inorder values to indices for fast lookup.

- Careful with the `pre` array indices for the right subtree start.
- TC O(N), SC O(N)

## Maximum width of a Binary Tree

Just BFS, but need to track indices for width. Normalize them each level or they blow up, remember to use long long.

- Indices can grow very large in a sparse tree, use `long long` and normalize indices at each level to prevent overflow.
- TC O(N), SC O(W)

## Minimum time taken to BURN the Binary Tree from a Node

First find the target node and map all parents using DFS. Then do a BFS starting from the target, spreading to children and parent.

- Don't forget to mark parent nodes as visited in BFS to avoid cycles.
- TC O(N), SC O(N)

## Construct Binary Tree from postorder and inorder

Use postorder's last element as root, find it in inorder to split subtrees. Recursively build left and right parts.

- Off-by-one indices for postorder array splits.
- TC O(N), SC O(N)

## Count total Nodes in a COMPLETE Binary Tree

A complete binary tree has certain properties we can exploit for quick height checks. Recursively count nodes by finding a perfect subtree at each step.

- The height function only traverses left, and 2^H for perfect subtree count.
- TC O((log N)^2), SC O(log N)

## Flatten Binary Tree to Linked List

Recursive DFS, process right subtree then left, then link current node to `prev` for the flattened list.

- Need to traverse in reverse pre-order (right -> left -> root) to build the list correctly.
- TC O(N), SC O(H)
