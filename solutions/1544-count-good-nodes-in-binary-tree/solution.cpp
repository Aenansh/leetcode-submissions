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
    int solve(TreeNode* root, int maxi) {
        if (!root)
            return 0;

        int good = 0;
        if (maxi <= root->val) {
            good = 1;
            maxi = root->val;
        }
        good += solve(root->left, maxi);
        good += solve(root->right, maxi);
        return good;
    }

public:
    int goodNodes(TreeNode* root) { return solve(root, root->val); }
};

