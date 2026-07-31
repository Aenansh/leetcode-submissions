class Solution {
    int solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        if (i < 0 || target < 0)
            return 0;

        if (target == 0)
            return 1;

        if (dp[i][target] != -1)
            return dp[i][target];

        int skip = solve(nums, target, i - 1, dp);
        int take = 0;
        if (nums[i] <= target)
            take = solve(nums, target - nums[i], nums.size() - 1, dp);

        return dp[i][target] = skip + take;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(nums, target, n - 1, dp);
    }
};
