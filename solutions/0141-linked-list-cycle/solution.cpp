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
    bool hasCycle(ListNode *head) {
        ListNode *runner = head;
        ListNode *slow = head;
        while(runner && runner->next)
        {
            runner = runner->next->next;
            if(runner == slow) return true;
            slow = slow->next;
        }
        return false;
    }
};
