class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = *max_element(begin(costs), end(costs));
        vector<int> sortt(n + 1, 0);
        for (int cost : costs) {
            sortt[cost]++;
        }

        for (int i = 1; i <= n; i++) {
            sortt[i] += sortt[i - 1];
        }

        int m = costs.size();
        vector<int> ans(m);

        for (int i = m - 1; i >= 0; i--) {
            ans[sortt[costs[i]] - 1] = costs[i];
            sortt[costs[i]]--;
        }

        int icecreams;
        for (int cost : ans) {
            if (cost <= coins) {
                icecreams++;
                coins -= cost;
            }
        }

        return icecreams;
    }
};
