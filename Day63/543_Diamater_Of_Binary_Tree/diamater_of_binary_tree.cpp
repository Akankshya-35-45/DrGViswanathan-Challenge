class Solution {
public:

    int diameter = 0;

    int height(TreeNode* root) {

        // If node is NULL, height is 0
        if (root == NULL)
            return 0;

        // Get height of left subtree
        int leftHeight = height(root->left);

        // Get height of right subtree
        int rightHeight = height(root->right);

        // Diameter passing through current node
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};
