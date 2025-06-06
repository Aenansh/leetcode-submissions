class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    table[i][j] = 0;

                else {
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        table[i][j] = table[i - 1][j] + table[i][j - 1];
                    }
                    else if(i - 1 < 0 && j - 1 >= 0) {
                        table[i][j] = table[i][j - 1];
                    }
                    else if(j - 1 < 0 && i - 1 >= 0) {
                        table[i][j] = table[i - 1][j];
                    }
                    else {
                        table[i][j] = 1;
                    }
                }
            }
        }
        return table[m - 1][n - 1];
    }
};
