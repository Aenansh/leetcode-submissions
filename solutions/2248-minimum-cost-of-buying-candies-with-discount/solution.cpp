class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();        
        sort(begin(cost), end(cost), greater<int>());

        int bill = 0;
        for(int i = 0; i < n; i += 3) {
            bill += cost[i];
            if(i + 1 < n) bill += cost[i + 1];
        }

        return bill;
    }
};
