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
    void solve(TreeNode* root, int& sum, int& size) {
        if (!root)
            return;

        sum += root->val;
        size += 1;
        solve(root->left, sum, size);
        solve(root->right, sum, size);
    }
    void calc(TreeNode* root, int& count) {
        if (!root)
            return;

        int sum = 0, size = 0;
        solve(root, sum, size);

        if (sum / size == root->val)
            count++;

        calc(root->left, count);
        calc(root->right, count);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        calc(root, count);
        return count;
    }
};
