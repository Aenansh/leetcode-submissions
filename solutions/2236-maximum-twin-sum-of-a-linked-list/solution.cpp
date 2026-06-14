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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> vals;
        while (temp) {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        int maxTwinSum = 0;
        for (int l = 0, r = vals.size() - 1; l < r; l++, r--) {
            maxTwinSum = max(maxTwinSum, vals[l] + vals[r]);
        }

        return maxTwinSum;
    }
};
