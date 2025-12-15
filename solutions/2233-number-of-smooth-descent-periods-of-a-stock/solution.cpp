class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        vector<long long> table(prices.size(), 1);

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) {
                table[i] = max(table[i - 1], table[i]) + 1;
            }
        }

        for(auto i : table) {
            ans += i;
        }
        return ans;
    }
};
