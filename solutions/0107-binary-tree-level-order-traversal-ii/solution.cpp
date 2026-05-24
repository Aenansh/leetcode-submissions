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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(root);

        vector<int> row;
        while (!q1.empty()) {
            TreeNode* temp = q1.front();
            q1.pop();
            row.push_back(temp->val);
            if (temp->left)
                q2.push(temp->left);
            if (temp->right)
                q2.push(temp->right);

            if (q1.empty()) {
                ans.push_back(row);
                row.clear();
                while (!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
