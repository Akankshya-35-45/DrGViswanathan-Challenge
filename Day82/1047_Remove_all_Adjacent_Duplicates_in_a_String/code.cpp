class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: key not found
        if (root == nullptr) {
            return nullptr;
        }
        // Search the left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // Search the right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // Node found
        else {
            // Case 1 and Case 2:
            // Node has zero or one child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Node has two children
            TreeNode* successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            root->val = successor->val;
            root->right = deleteNode(root->right,
                                     successor->val);
        }
        return root;
    }
};
