
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Target not found, or the tree is empty
        if (root == nullptr) {
            return nullptr;
        }

        // Target found: return the complete subtree
        if (root->val == val) {
            return root;
        }

        // Target is smaller: search only the left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }

        // Target is larger: search only the right subtree
        return searchBST(root->right, val);
    }
};
