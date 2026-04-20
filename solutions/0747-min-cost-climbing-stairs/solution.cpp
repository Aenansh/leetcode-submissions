class Solution {
    int solve(vector<int>& dp, vector<int>& cost, int idx) {
        if (idx <= 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int left = solve(dp, cost, idx - 1) + cost[idx - 1];
        int right = solve(dp, cost, idx - 2) + cost[idx - 2];

        return dp[idx] = min(left, right);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0, dp[1] = 0;
        return solve(dp, cost, n);
    }
};
