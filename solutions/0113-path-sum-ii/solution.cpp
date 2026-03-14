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
    void backtrack(TreeNode* root, int targetSum,
                   vector<int>& path, vector<vector<int>>& res) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == targetSum) {
            res.push_back(path);
        }
        backtrack(root->left, targetSum - root->val, path, res);
        backtrack(root->right, targetSum - root->val, path, res);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(root, targetSum, path, res);
        return res;
    }
};
