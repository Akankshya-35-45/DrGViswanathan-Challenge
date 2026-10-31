problem link:https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int count = 0;
        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            count++;
            if (count == k)
                return curr->val;
            curr = curr->right;
        }
        return -1;
    }
};


Why is the optimal approach better?
1. It uses the BST's sorted-order property directly.
2. It eliminates unnecessary sorting.
3. It doesn't need to store all node values.
4. It stops as soon as the kth smallest element is found.
5. It uses only the stack required for traversal.
The biggest lesson: Don't ignore the properties of the data structure you're working with!

Important interview points to remember
These are the questions an interviewer might ask:

Q1. Why do we use inorder traversal instead of preorder or postorder?
Because inorder traversal of a BST visits nodes in ascending sorted order.

Q2. Why is the answer at index k-1 in brute force?
Because vectors use zero-based indexing, whereas the question uses one-based indexing.

Q3. Why do we use a stack?
To simulate recursive inorder traversal without using the function call stack.

Q4. Why do we return immediately when count == k?
Because inorder traversal guarantees that the kth visited node is the kth smallest element. Visiting additional nodes is unnecessary.

Q5. Can we solve this recursively?
Yes! Recursive inorder traversal is another valid solution. However, it generally visits and stores all nodes if implemented with a vector. The iterative solution avoids storing all values and allows early termination.
