class Solution {
    int solve(int& m, int n, int i, vector<vector<int>>& dp) {
        if(n == 0) return 0;

        if(n < 0 || n < i) return 1e9;

        if(dp[n][i] != -1) return dp[n][i];

        int copypaste = solve(m, n - m + n, m - n, dp) + 2;
        int paste = solve(m, n - i, i, dp) + 1;

        return dp[n][i] = min(copypaste, paste);
    }
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int steps = solve(n, n - 1, 1, dp);
        return steps + 1;
    }
};
