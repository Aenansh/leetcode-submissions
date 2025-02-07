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
        if(!head || !head->next) return head;
        unordered_map<int,int> mp;
        vector<int> vec;
        ListNode* temp = head;
        while(temp){
            mp[temp->val]++;
            temp = temp->next;
        }
        for(auto i : mp){
            if(i.second == 1){
                vec.push_back(i.first);
            }
        }
        if(vec.empty()) return nullptr;
        sort(vec.begin(), vec.end());
        temp = head;
        for(int i = 0; i < vec.size(); i++){
            temp->val = vec[i];
            if(i < vec.size() - 1) temp = temp->next;
        }
        temp->next = nullptr;
        return head;
    }
};
