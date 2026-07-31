class Solution {
    int solve(vector<int>& prices, int i, int bought, int trans,
              vector<vector<vector<int>>>& dp) {
        if (i >= prices.size() || trans == 2)
            return 0;

        if (dp[i][bought][trans] != INT_MIN)
            return dp[i][bought][trans];
        if (!bought) {
            int buy = solve(prices, i + 1, 1, trans, dp) - prices[i];
            int notBuy = solve(prices, i + 1, 0, trans, dp);

            return dp[i][bought][trans] = max(buy, notBuy);
        }

        int sell = solve(prices, i + 1, 0, trans + 1, dp) + prices[i];
        int notSell = solve(prices, i + 1, 1, trans, dp);

        return dp[i][bought][trans] = max(sell, notSell);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n,
                                       vector<vector<int>>(2, vector<int>(2, INT_MIN)));

        return solve(prices, 0, 0, 0, dp);
    }
};
