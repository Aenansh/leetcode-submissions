class Solution {
    int findMedian(vector<int>& arr, int size) {
            return arr[size / 2];
    }

public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> flatten;
        for (auto& row : grid) {
            for (auto& el : row)
                flatten.push_back(el);
        }
        sort(begin(flatten), end(flatten));
        int remainder = flatten[0] % x;
        for (int i = 1; i < m * n; i++) {
            if (flatten[i] % x != remainder) {
                return -1;
            }
        }
        int median = findMedian(flatten, m * n);
        int ans = 0;
        for (int i = 0; i < m * n; i++) {
            ans += abs(median - flatten[i]) / x;
        }
        return ans;
    }
};
