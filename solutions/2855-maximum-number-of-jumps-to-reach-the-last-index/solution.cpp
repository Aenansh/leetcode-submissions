class Solution {
    int solve(vector<int>& nums, int target, int i, vector<int>& dp) {
        if (i == nums.size() - 1)
            return 0;

        if (dp[i] != -2)
            return dp[i];
        int maxJumps = -1;
        for (int idx = i + 1; idx < nums.size(); idx++) {
            int diff = nums[idx] - nums[i];
            if (diff >= -target && diff <= target) {
                int jumps = solve(nums, target, idx, dp);
                if (jumps != -1)
                    maxJumps = max(maxJumps, 1 + jumps);
            }
        }
        return dp[i] = maxJumps;
    }

public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), -2);
        return solve(nums, target, 0, dp);
    }
};
