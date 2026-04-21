class Solution {
    int solve(vector<vector<int>>& dp, vector<int>& coins, int amount,
              int idx) {
        if (idx == 0) {
            if (amount % coins[idx] == 0)
                return amount / coins[idx];
            return 1e9;
        }
        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        long notTake = solve(dp, coins, amount, idx - 1);
        long take = 1e9;
        if (coins[idx] <= amount)
            take = 1 + solve(dp, coins, amount - coins[idx], idx);

        return dp[idx][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int res = solve(dp, coins, amount, n - 1);
        return res >= 1e9 ? -1 : res;
    }
};
