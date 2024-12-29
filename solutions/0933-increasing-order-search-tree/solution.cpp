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
    void inorder(TreeNode* root, vector<int>& nums){
        if(!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    TreeNode* create(vector<int>& nums, int& i){
        if(i >= nums.size()) return nullptr;
        TreeNode* dummy = new TreeNode(nums[i]);
        dummy->right = create(nums, ++i);
        return dummy;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        int i = 0;
        return create(nums, i);
    }
};
