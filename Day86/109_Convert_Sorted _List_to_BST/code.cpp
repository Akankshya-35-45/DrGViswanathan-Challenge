class Solution {
public:
    ListNode* curr;
    TreeNode* build(int n) {
        // Base case
        if(n <= 0) {
            return NULL;
        }
        // Build left subtree
        TreeNode* leftSubtree = build(n / 2);
        // Create root using current list node
        TreeNode* root = new TreeNode(curr->val);
        // Move linked list pointer forward
        curr = curr->next;
        // Build right subtree
        root->right = build(n - n / 2 - 1);
        // Attach left subtree
        root->left = leftSubtree;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        curr = head;
        int n = 0;
        // Count linked list nodes
        ListNode* temp = head;
        while(temp != NULL) {
            n++;
            temp = temp->next;
        }
        return build(n);
    }
};


Key concepts to remember
1. A sorted linked list can be converted into a height-balanced BST.
2. Choosing middle elements helps maintain balance.
3. Inorder traversal of a BST produces sorted values.
4. We can simulate inorder traversal using recursion and a linked list pointer.
5. We can avoid an additional array by maintaining a pointer to the current linked list node.
6. Recursion helps construct the left subtree, root, and right subtree in the correct order.
