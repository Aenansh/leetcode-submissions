class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                int top_row = x + i;
                int bottom_row = x + (k - 1 - i);
                int current_col = y + j;
                swap(grid[top_row][current_col], grid[bottom_row][current_col]);
            }
        }

        return grid;
    }
};
