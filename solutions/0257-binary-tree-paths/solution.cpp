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
public:
    void backtrack(TreeNode* root, vector<string>& res, string& path) {
        if (!root) {
            return;
        }
        int original_size = path.length();
        path += to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(path);
        } else {
            path += "->";
            backtrack(root->left, res, path);
            backtrack(root->right, res, path);
        }
        path.resize(original_size);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path = "";
        backtrack(root, res, path);
        return res;
    }
};
