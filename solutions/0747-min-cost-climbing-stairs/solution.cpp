class Solution {
    int solve(vector<int>& cost, int i, vector<int>& dp) {
        if (i <= 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int two = solve(cost, i - 2, dp) + cost[i - 2];
        int one = solve(cost, i - 1, dp) + cost[i - 1];

        return dp[i] = min(two, one);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return solve(cost, n, dp);
    }
};
