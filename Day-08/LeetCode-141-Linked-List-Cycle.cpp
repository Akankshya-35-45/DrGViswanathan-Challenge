LEETCODE 141 – LINKED LIST CYCLE

Problem:
Return true if a linked list contains a cycle.

Cycle:
A cycle exists when a node points back to a previously visited node instead of NULL.

Approach 1: Hash Set
• Store visited node pointers.
• If a node is visited again → cycle exists.
• Time: O(n)
• Space: O(n)

Approach 2: Floyd's Cycle Detection (Optimal)
• Use two pointers:
  - Slow moves 1 step.
  - Fast moves 2 steps.
• If they meet → cycle exists.
• If fast or fast->next becomes NULL → no cycle.

Why compare pointers?
• Compare node addresses (`slow == fast`), not values.
• Different nodes may have the same value.

While condition:
while(fast != NULL && fast->next != NULL)
• Prevents invalid access when moving fast by two steps.

Time Complexity: O(n)
Space Complexity: O(1)







Floyd's Cycle Detection Code-
  class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }

        return false;
    }
};
