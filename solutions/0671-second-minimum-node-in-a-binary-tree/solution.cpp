/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void traversal(TreeNode* root, set<int>& s) {
        if(!root) return;
        s.insert(root->val);
        traversal(root->left, s);
        traversal(root->right, s);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        traversal(root, s);
        s.erase(s.begin());
        return s.size() >= 1 ? *s.begin() : -1;
    }
};
