class Solution {
    int solve(vector<int>& prices, int i, int bought, int k,
              vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || k == 0)
            return 0;

        if (dp[i][k][bought] != INT_MIN)
            return dp[i][k][bought];

        if (!bought) {
            int buy = solve(prices, i + 1, 1, k, dp) - prices[i];
            int notBuy = solve(prices, i + 1, 0, k, dp);

            return dp[i][k][bought] = max(buy, notBuy);
        }

        int sell = solve(prices, i + 1, 0, k - 1, dp) + prices[i];
        int notSell = solve(prices, i + 1, 1, k, dp);

        return dp[i][k][bought] = max(sell, notSell);
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(2, INT_MIN)));
        return solve(prices, 0, 0, k, dp);
    }
};
