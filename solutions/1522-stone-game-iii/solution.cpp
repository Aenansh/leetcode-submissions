class Solution {
    int solve(vector<int>& stoneValue, int i, vector<int>& dp) {
        if (i >= stoneValue.size())
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int n = stoneValue.size();

        int ans = -1e9;
        int currStones = 0;
        for (int k = 1; k <= 3 && i + k <= n; k++) {
            currStones += stoneValue[i + k - 1];
            ans = max(ans, currStones - solve(stoneValue, i + k, dp));
        }

        return dp[i] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n, INT_MIN);

        int res = solve(stoneValue, 0, dp);

        if (res == 0)
            return "Tie";
        if (res > 0)
            return "Alice";
        return "Bob";
    }
};
