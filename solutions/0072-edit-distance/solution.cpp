class Solution {
    int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if(dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = 1 + min({solve(i - 1, j - 1, s1, s2, dp),
                                   solve(i - 1, j, s1, s2, dp),
                                   solve(i, j - 1, s1, s2, dp)});
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, word1, word2, dp);
    }
};
