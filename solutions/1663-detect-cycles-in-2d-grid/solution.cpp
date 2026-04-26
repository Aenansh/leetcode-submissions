class Solution {
    int m, n;
    bool cycle(int x, int y, int px, int py, vector<vector<char>>& grid,
               vector<vector<bool>>& visited) {
        if (visited[x][y])
            return true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                grid[nx][ny] == grid[x][y]) {
                if (nx == px && ny == py)
                    continue;
                if (cycle(nx, ny, x, y, grid, visited))
                    return true;
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        unordered_map<char, pair<int, int>> parents;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && cycle(i, j, i, j, grid, visited))
                    return true;
            }
        }
        return false;
    }
};
