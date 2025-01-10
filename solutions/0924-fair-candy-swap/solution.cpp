class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long long atotal = 0, btotal = 0;
        for (auto i : aliceSizes) {
            atotal += i;
        }
        for (auto i : bobSizes) {
            btotal += i;
        }
        long long eqC = (atotal + btotal) / 2;
        unordered_map<int, int> mp;
        for (auto i : bobSizes) {
            mp[i]++;
        }
        for (int i = 0; i < aliceSizes.size(); i++) {
            if (mp[eqC + aliceSizes[i] - atotal] &&
                eqC + aliceSizes[i] - atotal == btotal - eqC + aliceSizes[i]) {
                return {aliceSizes[i], (int)(eqC + aliceSizes[i] - atotal)};
            }
        }
        return {-1, -1};
    }
};
