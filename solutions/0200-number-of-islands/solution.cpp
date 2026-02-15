class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        auto [a, b] = q.front();
                        q.pop();
                        for (auto d : dir) {
                            int r = a + d.first;
                            int c = b + d.second;
                            if (r >= 0 && r < m && c >= 0 && c < n &&
                                grid[r][c] == '1') {
                                q.push({r, c});
                                grid[r][c] = '0';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
