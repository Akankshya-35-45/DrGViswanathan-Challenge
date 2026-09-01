class Solution {
public:

    int findGCD(int a, int b) {
        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }

        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {

            int gcd = findGCD(curr->val, curr->next->val);

            ListNode* newNode = new ListNode(gcd);

            newNode->next = curr->next;

            curr->next = newNode;

            curr = newNode->next;
        }

        return head;
    }
};
