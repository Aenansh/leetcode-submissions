/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next)
            return false;
        ListNode* slow = head;
        ListNode* runner = head;
        while (slow && runner) {
            slow = slow->next;
            if (runner->next)
                runner = runner->next->next;
            else
                return false;
            if (slow == runner)
                return true;
        }
        return false;
    }
};
