class Solution {
    int solve(string& s1, string& s2, string& s3, int i, int j, int k,
              vector<vector<int>>& dp) {
        if (i >= s1.length()) {
            return s2.substr(j) == s3.substr(k);
        }
        if (j >= s2.length()) {
            return s1.substr(i) == s3.substr(k);
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s3[k]) {
            if (solve(s1, s2, s3, i + 1, j, k + 1, dp))
                return dp[i][j] = true;
        }
        if (s2[j] == s3[k]) {
            if (solve(s1, s2, s3, i, j + 1, k + 1, dp))
                return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};
