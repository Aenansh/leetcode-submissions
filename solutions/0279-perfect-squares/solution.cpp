class Solution {
    int solve(int n, vector<int>& dp) {
        if (n == 0)
            return 0;

        if (n < 0)
            return 1e9;

        if (dp[n] != -1)
            return dp[n];

        int count = 1e9;
        for (int i = 1; i * i <= n; i++) {
            count = min(count, 1 + solve(n - i * i, dp));
        }

        return dp[n] = count;
    }

public:
    int numSquares(int n) {
        int i = sqrt(n);
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
