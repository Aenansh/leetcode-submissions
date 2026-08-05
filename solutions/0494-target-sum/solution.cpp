class Solution {
    int totalSum;

    int solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        if (abs(target) > totalSum) {
            return 0;
        }

        int dpTargetIndex = target + totalSum;

        if (dp[i][dpTargetIndex] != -1) {
            return dp[i][dpTargetIndex];
        }

        int add = solve(nums, target - nums[i], i + 1, dp);
        int sub = solve(nums, target + nums[i], i + 1, dp);

        return dp[i][dpTargetIndex] = add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (abs(target) > totalSum)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));
        return solve(nums, target, 0, dp);
    }
};
