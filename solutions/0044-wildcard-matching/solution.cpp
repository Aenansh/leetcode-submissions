class Solution {
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i == s.length() && j == p.length())
            return true;

        if (j == p.length())
            return false;

        if (i == s.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (p[j] == '*') {
            int one = solve(s, p, i + 1, j, dp);
            int none = solve(s, p, i, j + 1, dp);

            return dp[i][j] = one || none;
        }

        if (p[j] == '?' || s[i] == p[j]) {
            return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
        }

        return false;
    }

public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s, p, 0, 0, dp);
    }
};
