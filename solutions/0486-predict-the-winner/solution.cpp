class Solution {
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j)
            return 0;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        return dp[i][j] = max(nums[i] - solve(nums, i + 1, j, dp),
                              nums[j] - solve(nums, i, j - 1, dp));
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        int res = solve(nums, 0, n - 1, dp);
        return res >= 0;
    }
};
