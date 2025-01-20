class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxProfit = 0;
        int j = 0;
        for(int i = 1; i < prices.size(); i++){
            profit = prices[i] - prices[j];
            maxProfit = max(maxProfit, profit);
            if(profit < 0){
                profit = 0;
                j++;
                i = j;
            }
        }
        return maxProfit;
    }
};
