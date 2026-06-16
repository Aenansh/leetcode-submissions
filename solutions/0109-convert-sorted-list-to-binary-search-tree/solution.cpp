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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    ListNode* middle(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = nullptr;
        return slow;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        if (!head->next)
            return new TreeNode(head->val);

        ListNode* mid = middle(head);
        TreeNode* tree = new TreeNode(mid->val);
        tree->left = sortedListToBST(head);
        tree->right = sortedListToBST(mid->next);
        return tree;
    }
};
