class Solution {
    void backtrack(int n, int li, vector<int>& p, vector<int>& nums,
                   set<vector<int>>& res, unordered_map<int, bool>& occ) {
        if (p.size() == n) {
            res.insert(p);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(occ[i]) continue;
            // if(i - 1 >= 0 && nums[i] == nums[i - 1]) continue;
            p.push_back(nums[i]);
            li = i;
            occ[i] = true;
            backtrack(n, li, p, nums, res, occ);
            p.pop_back();
            occ[li] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        vector<int> perm;
        int lastind = -1;
        int n = nums.size();
        unordered_map<int, bool> occ;
        backtrack(n, lastind, perm, nums, res, occ);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
