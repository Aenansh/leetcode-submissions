class Solution {
    int solve(string& word1, string& word2, int i, int j,
              vector<vector<int>>& dp) {
        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return solve(word1, word2, i - 1, j - 1, dp);

        return dp[i][j] = 1 + min({solve(word1, word2, i, j - 1, dp),
                                   solve(word1, word2, i - 1, j, dp),
                                   solve(word1, word2, i - 1, j - 1, dp)});
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(word1, word2, m - 1, n - 1, dp);
    }
};
