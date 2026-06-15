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
    int maxDepth(TreeNode* root, int& diam) {
        if(!root) return 0;
        int leftD = maxDepth(root->left, diam);
        int rightD = maxDepth(root->right, diam);

        diam = max(diam, leftD + rightD);

        return 1 + max(leftD, rightD);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        maxDepth(root, diam);
        return diam;
    }
};
