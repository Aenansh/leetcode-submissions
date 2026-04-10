class Solution {
    bool canTake(vector<int>& weights, int days, int w) {
        int n = weights.size();
        int currDay = 1, currW = 0;
        for(int i = 0; i < n; i++) {
            if(currW + weights[i] > w) {
                currDay++;
                currW = 0;
            }
            currW += weights[i];
        }
        return currDay <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = 0;
        for (int& w : weights)
            totalWeight += w;

        int l = *max_element(begin(weights), end(weights)), r = totalWeight;
        int minWeight = totalWeight;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canTake(weights, days, mid)) {
                minWeight = min(minWeight, mid);
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return minWeight;
    }
};
