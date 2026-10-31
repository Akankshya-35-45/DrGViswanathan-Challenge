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
