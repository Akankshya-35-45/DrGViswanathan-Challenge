# LeetCode 226: Invert Binary Tree
## Day 100 of 100 Days of Code
### Problem Statement
Given the root of a binary tree, invert the tree and return its root.
Inverting a binary tree means swapping the left and right child nodes of every node in the tree, creating a mirror image of the original tree.
### Example 1
Input:
```cpp
root = [4,2,7,1,3,6,9]
```
Output:
```cpp
[4,7,2,9,6,3,1]
```
Explanation:
- Swap the left and right children of node 4 (2 and 7).
- Swap the children of node 2 (1 and 3).
- Swap the children of node 7 (6 and 9).
- Continue until every node has been processed.
### Example 2
Input:
```cpp
root = [2,1,3]
```
Output:
```cpp
[2,3,1]
```
### Example 3
Input:
```cpp
root = []
```
Output:
```cpp
[]
```
Explanation: An empty tree remains empty.
### Approach 1: Recursive DFS (Depth First Search)
#### Intuition
The binary tree can be inverted by recursively swapping the left and right child pointers of every node.
At each node:
1. Check whether the current node is NULL.
2. Swap its left and right children.
3. Recursively invert the left subtree.
4. Recursively invert the right subtree.
5. Return the current root.
#### C++ Code
```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```
#### Line-by-Line Explanation
1. `TreeNode* invertTree(TreeNode* root)` defines a function that takes the root pointer and returns the root of the inverted tree.
2. `if (root == nullptr)` checks whether the current node is empty.
3. `return nullptr` stops recursion when a null node is reached. This is the base condition.
4. `swap(root->left, root->right)` exchanges the left and right child pointers of the current node.
5. `invertTree(root->left)` recursively inverts the left subtree.
6. `invertTree(root->right)` recursively inverts the right subtree.
7. `return root` returns the modified root after the tree has been inverted.
#### Dry Run
Input:
```cpp
root = [4,2,7,1,3,6,9]
```
Initial Tree:
```text
          4
        /   \
       2     7
      / \   / \
     1   3 6   9
```
Step 1: Start at node 4.
- Swap its left child 2 with its right child 7.
```text
          4
        /   \
       7     2
```
Step 2: Process node 7.
- Swap its children 6 and 9.
```text
          4
        /   \
       7     2
      / \
     9   6
```
Step 3: Process node 2.
- Swap its children 1 and 3.
```text
          4
        /   \
       7     2
      / \   / \
     9   6 3   1
```
Step 4: Process leaf nodes.
- Nodes 9, 6, 3 and 1 have no children.
- Recursive calls reach nullptr and return.
Final Output:
```cpp
[4,7,2,9,6,3,1]
```
#### Complexity Analysis
- Time Complexity: O(n), where n is the number of nodes. Every node is visited exactly once, and swapping its children takes constant time.
- Space Complexity: O(h), where h is the height of the tree. The recursion call stack stores function calls up to the height of the tree. In a balanced tree, it is O(log n), while in a skewed tree, it can be O(n).
### Approach 2: Iterative BFS (Breadth First Search)
#### Intuition
Instead of using recursion, we can invert the binary tree using a queue and level-order traversal.
BFS processes nodes level by level. At every node, we swap its left and right children and add its existing children to the queue for further processing.
#### Algorithm
1. If the root is nullptr, return nullptr.
2. Create a queue to store tree node pointers.
3. Push the root into the queue.
4. Continue while the queue is not empty.
5. Get and remove the front node.
6. Swap its left and right children.
7. Push its non-null children into the queue.
8. Return the root.
#### C++ Code
```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            swap(curr->left, curr->right);
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
        return root;
    }
};
```
Include the queue header:
```cpp
#include <queue>
```
#### Line-by-Line Explanation
1. `if (root == nullptr)` checks whether the tree is empty.
2. `queue<TreeNode*> q` creates a queue that stores pointers to tree nodes.
3. `q.push(root)` inserts the root node into the queue.
4. `while (!q.empty())` continues processing until the queue becomes empty.
5. `TreeNode* curr = q.front()` stores the pointer to the front node.
6. `q.pop()` removes the front node from the queue.
7. `swap(curr->left, curr->right)` swaps the left and right child pointers.
8. `if (curr->left != nullptr)` checks whether the left child exists.
9. `q.push(curr->left)` inserts the left child into the queue.
10. `if (curr->right != nullptr)` checks whether the right child exists.
11. `q.push(curr->right)` inserts the right child into the queue.
12. `return root` returns the inverted tree.
#### Dry Run
Input:
```cpp
root = [4,2,7,1,3,6,9]
```
The BFS traversal processes nodes level by level.
| Step | Current Node | Operation | Queue After Processing |
|---|---|---|---|
| 1 | 4 | Swap 2 and 7 | [7,2] |
| 2 | 7 | Swap 6 and 9 | [2,9,6] |
| 3 | 2 | Swap 1 and 3 | [9,6,3,1] |
| 4 | 9 | No children | [6,3,1] |
| 5 | 6 | No children | [3,1] |
| 6 | 3 | No children | [1] |
| 7 | 1 | No children | [] |
Final Output:
```cpp
[4,7,2,9,6,3,1]
```
#### Complexity Analysis
- Time Complexity: O(n), because every node is inserted, removed and processed once.
- Space Complexity: O(w), where w is the maximum width of the tree. In the worst case, the queue can store O(n) nodes.
### Comparison of Both Approaches
| Criteria | Recursive DFS | Iterative BFS |
|---|---|---|
| Technique | Recursion | Queue |
| Traversal | Depth First Search | Breadth First Search |
| Time Complexity | O(n) | O(n) |
| Space Complexity | O(h) | O(w) |
| Extra Structure | Recursion Stack | Queue |
| Implementation | Short and simple | Slightly longer |
### Why Recursive DFS Is Preferred
Both approaches are optimal because every node must be visited at least once to invert the entire tree.
Recursive DFS is preferred because:
- The problem naturally follows a recursive structure.
- The implementation is concise and easy to understand.
- It uses the tree's parent-child relationships directly.
- It avoids explicitly creating a queue.
BFS is also an optimal solution and is useful when an iterative approach is required.
### Important Concepts Learned
- Binary Trees
- TreeNode structure
- Pointers in C++
- nullptr and base conditions
- Recursion
- Depth First Search (DFS)
- Breadth First Search (BFS)
- Queue
- Pointer swapping
- Tree traversal
### Key Takeaway
The main operation in this problem is:
```cpp
swap(root->left, root->right);
```
It swaps the left and right child pointers of a node. By applying this operation to every node using DFS or BFS, we obtain the mirror image of the original binary tree.
### Complexity Summary
| Approach | Time Complexity | Space Complexity |
|---|---|---|
| Recursive DFS | O(n) | O(h) |
| Iterative BFS | O(n) | O(w) |
### Conclusion
LeetCode 226 helped strengthen my understanding of binary tree traversal, recursion, pointers and iterative BFS. It demonstrated how a simple pointer-swapping operation, combined with tree traversal, can transform an entire binary tree.
