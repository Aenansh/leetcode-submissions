class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> prefix(m, vector<long long>(n, 0));
        prefix[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            prefix[i][0] = prefix[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            prefix[0][j] = prefix[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefix[i][j] =
                    (prefix[i][j - 1] + prefix[i - 1][j] + grid[i][j]) -
                    prefix[i - 1][j - 1];
            }
        }

        for (int i = 0; i < m - 1; i++) {
            long long lower = prefix[m - 1][n - 1] - prefix[i][n - 1];
            if (lower == prefix[i][n - 1])
                return true;
        }
        for (int j = 0; j < n - 1; j++) {
            long long right = prefix[m - 1][n - 1] - prefix[m - 1][j];
            if (right == prefix[m - 1][j])
                return true;
        }
        return false;
    }
};
