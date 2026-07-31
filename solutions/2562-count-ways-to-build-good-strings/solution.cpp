class Solution {
    int MOD = 1e9 + 7;

    int solve(int& low, int& high, int& zero, int& one, int sum,
              vector<int>& dp) {
        if (sum > high)
            return 0;

        if (dp[sum] != -1)
            return dp[sum];

        int count = sum >= low ? 1 : 0;

        int takeOne = solve(low, high, zero, one, sum + one, dp);
        int takeZero = solve(low, high, zero, one, sum + zero, dp);

        return dp[sum] = (count + (0LL + takeOne + takeZero) % MOD) % MOD;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(low, high, zero, one, 0, dp);
    }
};
