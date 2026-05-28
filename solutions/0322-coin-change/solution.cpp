class Solution {
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return 1e9;

        if(dp[amount] != -1) return dp[amount];

        int count = 1e9;
        for (int i = 0; i < coins.size(); i++) {
            count = min(count, 1 + solve(coins, amount - coins[i], dp));
        }

        return dp[amount] = count;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
