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
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;
        ListNode* slow = head;
        ListNode* runner = head;
        while (runner && runner->next) {
            slow = slow->next;
            runner = runner->next->next;
            if (slow == runner)
                break;
        }
        if (!runner || !runner->next)
            return nullptr;
        runner = head;
        while (runner != slow) {
            runner = runner->next;
            slow = slow->next;
        }
        return slow;
    }
};
