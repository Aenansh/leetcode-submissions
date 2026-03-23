class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int mod = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<long long>> minx(m, vector<long long>(n, 0));
        vector<vector<long long>> maxx(m, vector<long long>(n, 0));

        minx[0][0] = grid[0][0];
        maxx[0][0] = grid[0][0];

        for (int j = 1; j < n; j++) {
            minx[0][j] = grid[0][j] * minx[0][j - 1];
            maxx[0][j] = grid[0][j] * maxx[0][j - 1];
        }

        for (int i = 1; i < m; i++) {
            minx[i][0] = grid[i][0] * minx[i - 1][0];
            maxx[i][0] = grid[i][0] * maxx[i - 1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long current = grid[i][j];
                long long p1 = current * minx[i][j - 1];
                long long p2 = current * minx[i - 1][j];
                long long p3 = current * maxx[i][j - 1];
                long long p4 = current * maxx[i - 1][j];

                minx[i][j] = min({p1, p2, p3, p4});
                maxx[i][j] = max({p1, p2, p3, p4});
            }
        }
        if(maxx.back().back() < 0) return -1;
        return maxx.back().back() % mod;
    }
};
