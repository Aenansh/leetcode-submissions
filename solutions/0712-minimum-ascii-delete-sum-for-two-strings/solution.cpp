class Solution {
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0) {
            int asciiVal = 0;
            while (j >= 0) {
                asciiVal += (int)s2[j--];
            }
            return asciiVal;
        }
        if (j < 0) {
            int asciiVal = 0;
            while (i >= 0) {
                asciiVal += (int)s1[i--];
            }
            return asciiVal;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return solve(s1, s2, i - 1, j - 1, dp);

        return dp[i][j] = min(solve(s1, s2, i - 1, j, dp) + (int)s1[i],
                              solve(s1, s2, i, j - 1, dp) + (int)s2[j]);
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(s1, s2, m - 1, n - 1, dp);
    }
};
