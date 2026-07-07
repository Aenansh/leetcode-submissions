class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int Find(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = Find(parent[u]);
    }
    void Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv)
            return;
        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        int m = grid.size();
        int n = grid[0].size();

        DSU d(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = n * i + j;
                if (grid[i][j] == 1) {
                    for (int t = 0; t < 4; t++) {
                        int ni = i + dx[t];
                        int nj = j + dy[t];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                            grid[ni][nj] == 1) {
                            int ncurr = n * ni + nj;
                            d.Union(curr, ncurr);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = i * n + j;
                if (grid[i][j] == 1)
                    ans = max(ans, d.size[d.Find(curr)]);
            }
        }
        return ans;
    }
};
