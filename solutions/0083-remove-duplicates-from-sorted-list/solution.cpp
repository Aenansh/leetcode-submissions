/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* curr = head;
        ListNode* after = head->next;
        while(after)
        {
            if(curr->val == after->val)
            {
                curr->next = after->next;
                after = curr->next;
            }
            else
            {
                curr = curr->next;
                after = after->next;
            }
        }
        return head;
    }
};
