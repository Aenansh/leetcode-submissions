class Solution {
    int solve(vector<int>& pref, int i, int j, vector<vector<int>>& dp) {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = max(
                   (pref[j + 1] - pref[i + 1]) - solve(pref, i + 1, j, dp),
                   (pref[j] - pref[i]) - solve(pref, i, j - 1, dp));
    }

public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(pref, 0, n - 1, dp);
    }
};
