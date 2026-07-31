class Solution {
    int solve(vector<int>& prices, int fee, int i, int bought,
              vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;

        if (dp[i][bought] != INT_MIN)
            return dp[i][bought];

        if (!bought) {
            int buy = solve(prices, fee, i + 1, 1, dp) - prices[i];
            int notBuy = solve(prices, fee, i + 1, 0, dp);

            return dp[i][bought] = max(buy, notBuy);
        }

        int sell = solve(prices, fee, i + 1, 0, dp) + prices[i] - fee;
        int notSell = solve(prices, fee, i + 1, 1, dp);

        return dp[i][bought] = max(sell, notSell);
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));

        return solve(prices, fee, 0, 0, dp);
    }
};
