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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, TreeNode*> roots;

        for (auto desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int branch = desc[2];

            if (!nodes[child])
                nodes[child] = new TreeNode(child);

            if (roots.find(parent) == roots.end() &&
                nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
                roots[parent] = nodes[parent];
            }
            if (roots.find(child) != roots.end())
                roots.erase(child);

            if (branch == 1) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
        }
        return roots.begin()->second;
    }
};
