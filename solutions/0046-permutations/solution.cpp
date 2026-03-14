class Solution {
public:
    void backtrack(int n, vector<int>& p, vector<int>& nums, 
    vector<vector<int>>& res, unordered_map<int, bool>& occ) {
        if(p.size() == n) {
            res.push_back(p);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(occ[nums[i]]) continue;
            p.push_back(nums[i]);
            occ[nums[i]]= true;
            backtrack(n, p, nums, res, occ);
            int last = p.back();
            p.pop_back();
            occ[last] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, bool> occ;
        vector<int> perm;
        int n = nums.size();
        backtrack(n, perm, nums, res, occ);
        return res;
    }
};
