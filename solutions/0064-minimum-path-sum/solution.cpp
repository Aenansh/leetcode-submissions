class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> upperRow = grid[0];

        for (int i = 1; i < n; i++) {
            upperRow[i] += upperRow[i - 1];
        }

        for (int i = 1; i < m; i++) {
            vector<int> currRow = grid[i];
            currRow[0] += upperRow[0];
            for (int j = 1; j < n; j++) {
                currRow[j] += min(upperRow[j], currRow[j - 1]);
            }
            upperRow = currRow;
        }

        return upperRow.back();
    }
};
