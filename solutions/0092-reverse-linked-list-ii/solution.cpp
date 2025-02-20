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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        vector<int> vals;
        ListNode* it = head;
        for(int i = 1; i < left; i++){
            it = it->next;
        }
        ListNode* dummy = it;
        for(int i = left; i <= right; i++){
            vals.push_back(it->val);
            it = it->next;
        }
        for(int i = left; i <= right; i++){
            dummy->val = vals.back();
            vals.pop_back();
            dummy = dummy->next;
        }
        return head;
    }
};
