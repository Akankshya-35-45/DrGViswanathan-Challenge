class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                // First leaf found is the nearest leaf
                if (node->left == NULL && node->right == NULL)
                    return depth;

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            depth++;
        }

        return depth;
    }
};
