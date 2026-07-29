class Solution {
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j < 0) {
            return 1;
        }
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int skip = solve(s, t, i - 1, j, dp);
        int take = 0;
        if (s[i] == t[j])
            take = solve(s, t, i - 1, j - 1, dp);

        return dp[i][j] = skip + take;
    }

public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(s, t, m - 1, n - 1, dp);
    }
};
