class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int row = grid.size(), col = grid[0].size();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 1) {
                    int p = 4;
                    if (c - 1 >= 0)
                        p -= grid[r][c - 1] == 1 ? 1 : 0;
                    if (c + 1 < col)
                        p -= grid[r][c + 1] == 1 ? 1 : 0;
                    if (r - 1 >= 0)
                        p -= grid[r - 1][c] == 1 ? 1 : 0;
                    if (r + 1 < row)
                        p -= grid[r + 1][c] == 1 ? 1 : 0;
                    perimeter += p;
                }
            }
        }
        return perimeter;   
    }
};
