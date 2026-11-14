# Day 98 – Same Tree (LeetCode 100)

## Problem Statement
Given the roots of two binary trees `p` and `q`, determine whether they are identical.
Two binary trees are considered identical if:
- They have the same structure.
- Their corresponding nodes have the same values.
Return `true` if both trees are identical; otherwise, return `false`.
**Problem Link:** https://leetcode.com/problems/same-tree/
**Difficulty:** Easy
**Topic:** Binary Tree, Recursion, Depth First Search (DFS)

## Approach – Recursive DFS

### Intuition
We use recursion to compare both binary trees node by node.
At every step, we check three conditions:
1. If both nodes are NULL, they are identical at that position, so return `true`.
2. If only one node is NULL, their structures are different, so return `false`.
3. If the values of the current nodes are different, return `false`.
If none of these conditions is satisfied, we recursively compare:
- The left subtree of the first tree with the left subtree of the second tree.
- The right subtree of the first tree with the right subtree of the second tree.
Both recursive calls must return `true` for the complete trees to be identical.

### Algorithm
1. Start by comparing the root nodes of both trees.
2. If both nodes are NULL, return `true`.
3. If either node is NULL, return `false`.
4. If their values are different, return `false`.
5. Recursively compare their left children.
6. Recursively compare their right children.
7. Return the logical AND (`&&`) of both recursive calls.

## C++ Code
```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Base Case 1: Both nodes are NULL
        if (p == NULL && q == NULL) {
            return true;
        }

        // Base Case 2: One node is NULL
        if (p == NULL || q == NULL) {
            return false;
        }

        // Check whether node values are different
        if (p->val != q->val) {
            return false;
        }

        // Recursively compare left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
```

## Code Explanation

### 1. Function Declaration
```cpp
bool isSameTree(TreeNode* p, TreeNode* q)
```
The function takes the root nodes of two binary trees and returns a boolean value.

### 2. First Base Case
```cpp
if (p == NULL && q == NULL) {
    return true;
}
```
If both nodes are NULL, both trees have empty positions at the same location. Therefore, they match.

### 3. Second Base Case
```cpp
if (p == NULL || q == NULL) {
    return false;
}
```
If only one node is NULL, the structures are different. Therefore, return false.

### 4. Compare Node Values
```cpp
if (p->val != q->val) {
    return false;
}
```
If the values of the corresponding nodes are different, the trees cannot be identical.

### 5. Recursive Calls
```cpp
return isSameTree(p->left, q->left) &&
       isSameTree(p->right, q->right);
```
This is the main part of the solution.
- `isSameTree(p->left, q->left)` compares the left subtrees.
- `isSameTree(p->right, q->right)` compares the right subtrees.
- `&&` ensures that both recursive calls must return true.
If either subtree is different, the entire expression returns false.

## Dry Run

**Input:**
```cpp
p = [1,2,3]
q = [1,2,3]
```

**Tree Structure:**
```text
       1                 1
      / \               / \
     2   3             2   3
```

**Execution:**

| Step | Comparison | Result |
|------|------------|--------|
| 1 | Compare root: 1 == 1 | Match |
| 2 | Compare left child: 2 == 2 | Match |
| 3 | Compare left children of 2 | Both NULL |
| 4 | Compare right children of 2 | Both NULL |
| 5 | Compare right child: 3 == 3 | Match |
| 6 | Compare left children of 3 | Both NULL |
| 7 | Compare right children of 3 | Both NULL |

Both left and right subtree comparisons return true.
```cpp
true && true = true
```

**Output:**
```cpp
true
```

**Explanation:** Both trees have the same structure and corresponding node values.

## Complexity Analysis

### Time Complexity: O(N)
Where N is the number of corresponding nodes visited.
Each corresponding node is compared only once. In the worst case, when both trees are identical, every node is visited.

More precisely, the worst-case time complexity is O(min(N, M)), where N and M are the numbers of nodes in the two trees.

### Space Complexity: O(H)
The recursive calls are stored in the call stack.
- Balanced Binary Tree: O(log N)
- Skewed Binary Tree: O(N)
Where H represents the height of the tree.

## Why Recursive DFS?
- It naturally handles the hierarchical structure of binary trees.
- Each corresponding node is visited only once.
- It checks both node values and tree structure.
- It avoids using an additional queue or manually maintained stack.
- It achieves optimal O(N) time complexity in the worst case when both trees are identical.

## Key Learnings
- Understanding recursion in binary trees.
- Identifying and handling base cases.
- Comparing corresponding nodes.
- Understanding the logical AND (`&&`) operator.
- Using Depth First Search (DFS) to traverse binary trees.
- Understanding recursion stack space complexity.


#100DaysOfCode #Day100 #LeetCode #DSA #CPP #BinaryTree #Recursion #DFS #ProblemSolving
