class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxans = 0, index = 0;
        for(int i = 1; i < prices.size(); i++) {
            int p = prices[i] - prices[index];
            if(p < 0) index = i;
            else maxans = max(maxans, p);
        }
        return maxans;
    }
};
