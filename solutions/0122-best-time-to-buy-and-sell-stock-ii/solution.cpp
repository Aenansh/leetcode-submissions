class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, -1);

        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i - 1]) {
                dp[i] = dp[i - 1] > -1 ? dp[i - 1] : i - 1;
            }
        }

        int max_profit = 0;
        int i = n - 1;
        while(i >= 0) {
            if(dp[i] > -1) {
                max_profit += prices[i] - prices[dp[i]];
                i = dp[i] - 1;
            }
            else i--;
        }

        return max_profit;
    }
};
