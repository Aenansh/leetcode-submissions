class Solution {
    int solve(vector<int>& prices, int i, int bought, vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;

        if (dp[i][bought] != INT_MAX)
            return dp[i][bought];

        if (!bought) {
            int buy = solve(prices, i + 1, 1, dp) - prices[i];
            int notBuy = solve(prices, i + 1, 0, dp);

            return dp[i][bought] = max(buy, notBuy);
        }

        int sell = solve(prices, i + 2, 0, dp) + prices[i];
        int notSell = solve(prices, i + 1, 1, dp);

        return dp[i][bought] = max(sell, notSell);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
        return solve(prices, 0, 0, dp);
    }
};
