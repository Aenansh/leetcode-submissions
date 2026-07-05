class Solution {
    int solve(string& w1, string& w2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (w1[i] == w2[j]) {
            return dp[i][j] = solve(w1, w2, i - 1, j - 1, dp);
        }

        return dp[i][j] = 1 + min(solve(w1, w2, i - 1, j, dp),
                              solve(w1, w2, i, j - 1, dp));
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(word1, word2, m - 1, n - 1, dp);
    }
};
