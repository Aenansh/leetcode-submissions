class Solution {
    bool backtrack(string& str, int i, int open, vector<vector<int>>& dp) {
        if (open < 0)
            return 0;
            
        if (i == str.length())
            return open == 0;

        if (open > str.length() - i)
            return false;

        if (dp[i][open] != -1)
            return dp[i][open];

        if (str[i] == '(') {
            return dp[i][open] = backtrack(str, i + 1, open + 1, dp);
        }
        if (str[i] == ')') {
            return dp[i][open] = backtrack(str, i + 1, open - 1, dp);
        }
        return dp[i][open] = backtrack(str, i + 1, open + 1, dp) ||
                             backtrack(str, i + 1, open - 1, dp) ||
                             backtrack(str, i + 1, open, dp);
    }

public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return backtrack(s, 0, 0, dp);
    }
};
