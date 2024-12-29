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
    TreeNode* treeBuild(int l, int r, vector<int>& nums){
        if(l > r)return nullptr;
        int mid = (l + r) / 2;
        TreeNode* dummy = new TreeNode(nums[mid]);
        dummy->left = treeBuild(l, mid - 1, nums);
        dummy->right = treeBuild(mid + 1, r, nums);
        return dummy;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        TreeNode* root = treeBuild(l, r, nums);
        return root;
    }
}; 
