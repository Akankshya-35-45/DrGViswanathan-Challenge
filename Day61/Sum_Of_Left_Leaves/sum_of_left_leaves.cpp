class Solution {
public:
    int dfs(TreeNode* root, bool isLeft) {
        // If node is empty
        if (root == NULL)
            return 0;
        // If current node is a leaf
        if (root->left == NULL && root->right == NULL) {
            // Add it only if it is a left child
            if (isLeft)
                return root->val;
            return 0;
        }
        // Recursively calculate left subtree
        int leftSum = dfs(root->left, true);
        // Recursively calculate right subtree
        int rightSum = dfs(root->right, false);
        return leftSum + rightSum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        // Root itself is not a left child
        return dfs(root, false);
    }
};
