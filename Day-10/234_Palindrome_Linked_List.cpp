class Solution {
public:

    // Reverse a linked list
    ListNode* reverse(ListNode* head){

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){

            ListNode* nextNode = curr->next; // Save next node

            curr->next = prev;               // Reverse link

            prev = curr;                     // Move prev

            curr = nextNode;                 // Move curr
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // One node or empty list is always a palindrome
        if(head == NULL || head->next == NULL)
            return true;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){

            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* secondHalf = reverse(slow->next);

        // Compare
        ListNode* firstHalf = head;

        while(secondHalf != NULL){

            if(firstHalf->val != secondHalf->val)
                return false;

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
