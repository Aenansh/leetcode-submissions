class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> xc(m, vector<int>(n, 0));
        vector<vector<int>> yc(m, vector<int>(n, 0));

        xc[0][0] = grid[0][0] == 'X' ? 1 : 0;
        yc[0][0] = grid[0][0] == 'Y' ? 1 : 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                else if (i - 1 >= 0 && j - 1 < 0) {
                    xc[i][j] = xc[i - 1][j] + (grid[i][j] == 'X' ? 1 : 0);
                    yc[i][j] = yc[i - 1][j] + (grid[i][j] == 'Y' ? 1 : 0);
                } else if (j - 1 >= 0 && i - 1 < 0) {
                    xc[i][j] = xc[i][j - 1] + (grid[i][j] == 'X' ? 1 : 0);
                    yc[i][j] = yc[i][j - 1] + (grid[i][j] == 'Y' ? 1 : 0);
                } else {
                    xc[i][j] = (xc[i - 1][j] + xc[i][j - 1] +
                                (grid[i][j] == 'X' ? 1 : 0)) -
                               xc[i - 1][j - 1];
                    yc[i][j] = (yc[i - 1][j] + yc[i][j - 1] +
                                (grid[i][j] == 'Y' ? 1 : 0)) -
                               yc[i - 1][j - 1];
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (xc[i][j] == yc[i][j] && xc[i][j] >= 1)
                    res++;
            }
        }
        return res;
    }
};
