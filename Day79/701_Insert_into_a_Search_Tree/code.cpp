##optimal using BST property (recursive stack)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } 
        else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};


##optimal approach using iterative
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* curr = root;
        while (true) {
            if (val < curr->val) {
                if (curr->left == nullptr) {
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            } 
            else {
                if (curr->right == nullptr) {
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            }
        }
        return root;
    }
};
