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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        ListNode* curr = head;

        while(curr && curr->next) {
            ListNode* nn = curr->next;
            curr->next = nn->next;
            nn->next = curr;
            prev->next = nn;
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};
