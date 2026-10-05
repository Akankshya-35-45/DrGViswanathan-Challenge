class Solution {
public:
    bool dfs(TreeNode* root, int targetSum) {

        // If tree/subtree is empty
        if (root == NULL)
            return false;

        // If current node is a leaf
        if (root->left == NULL && root->right == NULL) {

            // Check whether this leaf completes the target
            return targetSum == root->val;
        }

        // Subtract current node value
        int remaining = targetSum - root->val;

        // Search left or right subtree
        return dfs(root->left, remaining) ||
               dfs(root->right, remaining);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};
