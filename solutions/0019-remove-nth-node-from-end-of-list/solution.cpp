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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;
        ListNode *runner = head;
        ListNode *current = head;
        ListNode *before = head;
        for(int i = 0; i < n; i++)
        {
            runner = runner->next;
        }
        if(!runner)
        {
            head = head->next;
            return head;
        }
        while(runner)
        {
            runner = runner->next;
            before = current;
            current = current->next;
        }
        before->next = current->next;
        delete current;
        return head;
    }
};
