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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> trav;
        trav.push({root, 1});
        while(!trav.empty()){
            auto [node, depth] = trav.front();
            trav.pop();
            if(!node->left && !node->right) return depth; 
            if(node->left){
                trav.push({node->left, depth + 1});
            }
            if(node->right){
                trav.push({node->right, depth + 1});
            }
        }
        return 0;
    }
};
