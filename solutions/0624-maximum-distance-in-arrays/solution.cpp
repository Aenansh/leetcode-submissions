class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();

        int minNum = arrays[0].front();
        int maxNum = arrays[0].back();

        int maxAns = INT_MIN;
        for (int i = 1; i < m; i++) {
            maxAns = max({maxAns, abs(maxNum - arrays[i].front()),
                          abs(minNum - arrays[i].back())});

            minNum = min(minNum, arrays[i].front());
            maxNum = max(maxNum, arrays[i].back());
        }

        return maxAns;
    }
};
