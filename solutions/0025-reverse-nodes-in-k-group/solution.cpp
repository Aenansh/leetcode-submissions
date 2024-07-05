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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int count = 0;
        while(temp)
        {
            ++count;
            if(count >= k) break;
            temp = temp->next;
        }
        if(count < k) return head;

        temp = head;
        ListNode *h1 = head;

        for(int i = 0; i < k - 1; i++)
        {
            temp = temp->next;
        }

        ListNode *h2 = temp->next;
        temp->next = NULL;

        ListNode *b = NULL, *a = h1, *c = head;
        while(c)
        {
            a = a->next;
            c->next = b;
            b = c;
            c = a;
        }
        h1->next = reverseKGroup(h2, k);
        return temp;
    }
};
