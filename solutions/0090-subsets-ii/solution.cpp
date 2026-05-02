class Solution {
    void backtrack(set<vector<int>>& unique, vector<int>& sub,
                   vector<int>& nums, int i) {
        if (i == nums.size()) {
            unique.insert(sub);
            return;
        }

        backtrack(unique, sub, nums, i + 1);
        sub.push_back(nums[i]);
        backtrack(unique, sub, nums, i + 1);
        sub.pop_back();
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> unique;
        vector<int> sub;
        sort(begin(nums), end(nums));
        backtrack(unique, sub, nums, 0);
        return vector<vector<int>>(begin(unique), end(unique));
    }
};
