class Solution {
    void backtrack(int count, vector<int>& sub, vector<int>& nums,
                   vector<vector<int>>& res) {
        if (count == nums.size()) {
            res.push_back(sub);
            return;
        }
        backtrack(count + 1, sub, nums, res);
        sub.push_back(nums[count]);
        backtrack(count + 1, sub, nums, res);
        sub.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        int count = 0;
        backtrack(count, sub, nums, res);
        return res;
    }
};
