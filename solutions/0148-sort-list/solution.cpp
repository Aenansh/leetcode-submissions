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
    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* temp1, ListNode* temp2) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* next = dummy;
        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                next->next = temp1;
                temp1 = temp1->next;
            } else {
                next->next = temp2;
                temp2 = temp2->next;
            }
            next = next->next;
        }
        if (temp1) {
            next->next = temp1;
        } else {
            next->next = temp2;
        }
        ListNode* merged = dummy->next;
        delete dummy;
        return merged;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return merge(leftHead, rightHead);

    }
};
