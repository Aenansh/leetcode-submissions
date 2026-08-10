class Solution {
    int solve(int n, vector<int>& dp) {
        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int mul = -0;
        for (int i = 1; i < n; i++) {
            mul = max(mul, i * max(n - i, solve(n - i, dp)));
        }

        return dp[n] = mul;
    }

public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
