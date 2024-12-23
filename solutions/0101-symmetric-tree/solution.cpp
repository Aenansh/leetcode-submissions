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
    bool checkMirror(TreeNode* rleft, TreeNode* rright) {
        if (!rleft && !rright)
            return true;
        if (!rleft || !rright)
            return false;
        if (rleft->val != rright->val)
            return false;
        else
            return checkMirror(rleft->left, rright->right) && checkMirror(rright->left, rleft->right);
    }
    bool isSymmetric(TreeNode* root) {
        return checkMirror(root->left, root->right);
    }
};
