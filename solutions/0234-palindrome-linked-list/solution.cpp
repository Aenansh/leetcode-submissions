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
    bool isPalindrome(ListNode* head) {
        stack<int> rev;
        ListNode* temp = head;
        while(temp)
        {
            rev.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(!rev.empty())
        {
            if(rev.top() != temp->val)
            return false;
            else
            {
                temp = temp->next;
                rev.pop();
            }
        }
        return true;
    }
};
