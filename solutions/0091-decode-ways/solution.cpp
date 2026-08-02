class Solution {
    int solve(string& s, int i, vector<int>& dp) {
        if (i == s.length())
            return 1;

        if (dp[i] != -1)
            return dp[i];

        int one = 0;
        if (s[i] != '0')
            one = solve(s, i + 1, dp);
        int two = 0;
        if (i + 1 < s.length()) {
            if ((s[i] == '2' && s[i + 1] < '7') || s[i] == '1')
                two = solve(s, i + 2, dp);
        }

        return dp[i] = one + two;
    }

public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(s, 0, dp);
    }
};
