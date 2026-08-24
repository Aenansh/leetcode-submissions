class Solution {
    int solve(vector<int>& stones, int i, vector<int>& dp) {
        if (i == stones.size() - 1)
            return stones.back();

        if (dp[i] != -1e9)
            return dp[i];

        return dp[i] = max(solve(stones, i + 1, dp),
                           stones[i] - solve(stones, i + 1, dp));
    }

public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pref = stones;
        for (int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }

        vector<int> dp(n, -1e9);
        return solve(pref, 1, dp);
    }
};
