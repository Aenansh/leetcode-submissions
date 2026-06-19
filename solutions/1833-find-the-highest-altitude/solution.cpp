class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxPeak = 0, bigPeak = 0;
        for (int i = 0; i < gain.size(); i++) {
            bigPeak += gain[i];
            maxPeak = max(maxPeak, bigPeak);
        }
        return maxPeak;
    }
};
