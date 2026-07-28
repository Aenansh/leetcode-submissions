class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<int> upperRow(n, 0);
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 0)
                upperRow[i] = 1;
            else
                break;
        }

        for (int i = 1; i < m; i++) {
            vector<int> currRow(n, 0);
            if (obstacleGrid[i][0] == 0)
                currRow[0] = upperRow[0];
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    currRow[j] = currRow[j - 1] + upperRow[j];
                }
            }
            upperRow = currRow;
        }

        return upperRow.back();
    }
};
