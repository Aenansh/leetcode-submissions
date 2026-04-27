class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int, vector<pair<int, int>>> directions = {
            {1, {{0, -1}, {0, 1}}},  {2, {{1, 0}, {-1, 0}}},
            {3, {{0, -1}, {1, 0}}},  {4, {{0, 1}, {1, 0}}},
            {5, {{0, -1}, {-1, 0}}}, {6, {{0, 1}, {-1, 0}}}};

        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, pair<int, int>>> q;
        q.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int val = node.first;
            int x = node.second.first, y = node.second.second;

            for (int i = 0; i < 2; i++) {
                auto pd = directions[val][i];
                int nx = x + pd.first;
                int ny = y + pd.second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    int nval = grid[nx][ny];
                    for (int j = 0; j < 2; j++) {
                        auto npd = directions[nval][j];
                        int fx = nx + npd.first, fy = ny + npd.second;
                        if (fx >= 0 && fx < m && fy >= 0 && fy < n && fx == x && fy == y) {
                            q.push({nval, {nx, ny}});
                            visited[nx][ny] = true;
                            break;
                        }
                    }
                }
            }
        }
        return visited[m - 1][n - 1];
    }
};
