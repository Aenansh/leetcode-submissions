class Solution {
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j == t.length())
            return 1;
        if (i == s.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long notTake = solve(s, t, i + 1, j, dp);
        long long take = 0;
        if (s[i] == t[j])
            take = solve(s, t, i + 1, j + 1, dp);

        return dp[i][j] = (unsigned int)(take + notTake);
    }

public:
    int numDistinct(string s, string t) {
        if (s == t)
            return 1;
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return solve(s, t, 0, 0, dp);
    }
};
