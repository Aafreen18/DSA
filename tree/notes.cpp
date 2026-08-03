/*
=========================================================
                TYPES OF BINARY TREES
=========================================================

1. BALANCED BINARY TREE
---------------------------------------------------------
Definition:
- For every node, the height difference between its left
  and right subtree is at most 1.
- Each 

Condition:
- |height(left) - height(right)| <= 1

Example:

        1
      /   \
     2     3
    / \     \
   4   5     6

Properties:
- Height is O(log n) (approximately).
- Search, insertion, and deletion are efficient.
- AVL Tree and Red-Black Tree are examples of self-balanced BSTs.


=========================================================

2. PERFECT BINARY TREE
---------------------------------------------------------
Definition:
- Every internal node has exactly 2 children except leaf nodes.
- All leaf nodes are at the same level.

Example:

        1
      /   \
     2     3
    / \   / \
   4  5  6  7

Properties:
- Every level is completely filled.
- Number of nodes = 2^(h+1) - 1
- Number of leaves = 2^h
- Height = log2(n + 1) - 1


=========================================================

3. COMPLETE BINARY TREE
---------------------------------------------------------
Definition:
- Every level except possibly the last is completely filled.
- The last level is filled from LEFT to RIGHT
  without any gaps.

Example:

        1
      /   \
     2     3
    / \   /
   4   5 6

Valid because the last level is left-aligned.

Invalid Example:

        1
      /   \
     2     3
    /       \
   4         7

Reason:
- Node 7 appears while positions to its left are empty.

Applications:
- Binary Heap
- Heap Sort
- Priority Queue


=========================================================

4. ALMOST COMPLETE BINARY TREE
---------------------------------------------------------
Definition:
- In modern DSA, this is the SAME as a Complete Binary Tree.

Older books may define it separately as:
- All levels except the last are completely filled.
- The last level may be incomplete but must be filled
  from LEFT to RIGHT.

NOTE:
- In interviews (LeetCode, GFG, CLRS), treat
  "Almost Complete" and "Complete" as the same.


=========================================================

5. DEGENERATE (SKEWED) BINARY TREE
---------------------------------------------------------
Definition:
- Every node has only ONE child.

Types:

Left Skewed:

      1
     /
    2
   /
  3
 /
4


Right Skewed:

1
 \
  2
   \
    3
     \
      4

Properties:
- Height = n - 1
- Behaves like a Linked List.
- Search operations become O(n).
- Worst possible binary tree shape.


=========================================================
                    QUICK COMPARISON
=========================================================

Balanced:
✔ Height difference at every node <= 1

Perfect:
✔ Every internal node has 2 children
✔ All leaves at same level

Complete:
✔ All levels full except possibly last
✔ Last level filled left to right

Almost Complete:
✔ Same as Complete (modern terminology)

Degenerate / Skewed:
✔ Every node has only one child
✔ Looks like a linked list
✔ Height = n - 1

=========================================================
