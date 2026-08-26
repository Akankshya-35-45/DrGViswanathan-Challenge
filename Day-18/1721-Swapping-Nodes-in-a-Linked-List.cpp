class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // Step 1: Find the length of the linked list
        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        // Step 2: Find kth node from the beginning
        ListNode* first = head;

        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Step 3: Find kth node from the end
        int secondPos = n - k + 1;

        ListNode* second = head;

        for (int i = 1; i < secondPos; i++) {
            second = second->next;
        }

        // Step 4: Swap their values
        swap(first->val, second->val);

        return head;
    }
};
