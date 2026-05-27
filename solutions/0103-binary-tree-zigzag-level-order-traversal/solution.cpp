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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        vector<vector<int>> ans;
        vector<int> row;

        int idx = 1;

        q1.push(root);
        while(!q1.empty()) {
            TreeNode* temp = q1.front();
            q1.pop();
            row.push_back(temp->val);
            if(temp->left) q2.push(temp->left);
            if(temp->right) q2.push(temp->right);

            if(q1.empty()) {
                while(!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }
                if(idx % 2 == 0) reverse(row.begin(), row.end());
                ans.push_back(row);
                row.clear();
                idx++;
            }
        }
        return ans;
    }
};
