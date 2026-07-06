class Solution {
    int solve(int k, int n, vector<vector<int>>& dp) {
        if (n == 1 || n == 0)
            return n;
        if (k == 1)
            return n;

        if (dp[n][k] != -1)
            return dp[n][k];
        int minmax = INT_MAX;
        int L = 1, R = n;

        while (L <= R) {
            int M = L + (R - L) / 2;
            int breaks = solve(k - 1, M - 1, dp);
            int notBreaks = solve(k, n - M, dp);

            int moves = 1 + max(breaks, notBreaks);

            minmax = min(minmax, moves);
            if (breaks > notBreaks) {
                R = M - 1;
            } else
                L = M + 1;
        }

        return dp[n][k] = minmax;
    }

public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(k, n, dp);
    }
};
