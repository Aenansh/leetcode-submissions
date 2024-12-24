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
    void traverse(TreeNode* root, int& n){
        if(!root) return;
        n++;
        traverse(root->left, n);
        traverse(root->right, n);
    }
    int countNodes(TreeNode* root) {
        int n = 0;
        traverse(root, n);
        return n;
    }
};
