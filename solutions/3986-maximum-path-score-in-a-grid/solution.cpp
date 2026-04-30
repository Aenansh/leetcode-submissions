class Solution {
    int solve(vector<vector<int>>& grid, int k, int i, int j,
              vector<vector<vector<int>>>& dp) {
        if (i >= grid.size() || j >= grid[0].size())
            return -1e9;

        int currk = grid[i][j] == 0 ? 0 : 1;
        if (k - currk < 0)
            return -1e9;

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int right = solve(grid, k - currk, i, j + 1, dp);
        int down = solve(grid, k - currk, i + 1, j, dp);

        int bestPath = max(right, down);
        if (bestPath <= -1e8)
            dp[i][j][k] = -1e9;

        return dp[i][j][k] = grid[i][j] + max(right, down);
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int ans = solve(grid, k, 0, 0, dp);
        return ans <= -1e8 ? -1 : ans;
    }
};
