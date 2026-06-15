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
    int maxDepth(TreeNode* root, int& sum, unordered_map<TreeNode*, int>& dp) {
        if (!root)
            return 0;
        if (dp.find(root) != dp.end())
            return dp[root];

        int leftSum = max(0, maxDepth(root->left, sum, dp));
        int rightSum = max(0, maxDepth(root->right, sum, dp));

        sum = max(sum, leftSum + rightSum + root->val);

        return dp[root] = root->val + max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        int sum = INT_MIN;
        maxDepth(root, sum, dp);
        return sum;
    }
};
