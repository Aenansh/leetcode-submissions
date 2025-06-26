class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 < 0 && j - 1 < 0)
                    table[i][j] = grid[i][j];
                else if (i - 1 < 0 || j - 1 < 0) {
                    if (i - 1 < 0) {
                        table[i][j] = grid[i][j] + table[i][j - 1];
                    } else if (j - 1 < 0) {
                        table[i][j] = grid[i][j] + table[i - 1][j];
                    }
                } else {
                    table[i][j] =
                        grid[i][j] + min(table[i][j - 1], table[i - 1][j]);
                }
            }
        }
        return table[m - 1][n - 1];
    }
};
