class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        while (!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;

            dq.pop_front();

            for (int t = 0; t < 4; t++) {
                int nx = x + dx[t];
                int ny = y + dy[t];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    dist[nx][ny] > grid[nx][ny] + dist[x][y]) {
                    dist[nx][ny] = grid[nx][ny] + dist[x][y];
                    if (grid[nx][ny] == 1)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};
