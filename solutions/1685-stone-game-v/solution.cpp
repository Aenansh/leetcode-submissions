class Solution {
    int solve(vector<int>& stones, int i, int r, vector<vector<int>>& dp) {
        if (i == r) {
            return 0;
        }

        if (dp[i][r] != -1)
            return dp[i][r];

        int totalVal = 0;
        for (int idx = i; idx < r; idx++) {
            int leftSum = stones[idx] - (i > 0 ? stones[i - 1] : 0),
                rightSum = stones[r] - stones[idx];

            int currVal = 0;
            if (leftSum < rightSum) {
                currVal = solve(stones, i, idx, dp) + leftSum;
            } else if (leftSum > rightSum) {
                currVal = solve(stones, idx + 1, r, dp) + rightSum;
            } else {
                currVal = max(solve(stones, i, idx, dp),
                              solve(stones, idx + 1, r, dp)) +
                          leftSum;
            }
            totalVal = max(totalVal, currVal);
        }
        return dp[i][r] = totalVal;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        for (int i = 1; i < n; i++)
            stoneValue[i] += stoneValue[i - 1];

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(stoneValue, 0, n - 1, dp);
    }
};
