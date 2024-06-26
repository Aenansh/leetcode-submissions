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
    ListNode* reverseList(ListNode* head) {
        ListNode *after = head;
        ListNode *before = NULL;
        ListNode *current = head;
        while(after && current)
        {
            after = after->next;
            current->next = before;
            before = current;
             current = after;
        }
        head = before;
        return head;
    }
};
