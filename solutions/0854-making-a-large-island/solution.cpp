class DSU {
public:
    vector<int> size, parent;
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU d(n * n);

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                for (int k = 0; k < 4; k++) {
                    int row = i + dr[k];
                    int col = j + dc[k];
                    if (row >= 0 && row < n && col >= 0 && col < n &&
                        grid[row][col] == 1) {
                        int currNode = i * n + j;
                        int adjNode = row * n + col;
                        d.unionBySize(currNode, adjNode);
                    }
                }
            }
        }
        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    continue;

                unordered_set<int> ultp;
                int size = 1;
                for (int k = 0; k < 4; k++) {
                    int row = i + dr[k];
                    int col = j + dc[k];

                    if (row >= 0 && row < n && col >= 0 && col < n &&
                        grid[row][col] == 1) {
                        int currNode = i * n + j;
                        int adjNode = row * n + col;
                        int parent = d.findParent(adjNode);
                        if (ultp.find(parent) != ultp.end())
                            continue;
                        ultp.insert(parent);
                        size += d.size[parent];
                    }
                }
                maxSize = max(maxSize, size);
            }
        }
        for(int i = 0; i < n * n; i++) {
            maxSize = max(maxSize, d.size[d.findParent(i)]);
        }
        return maxSize;
    }
};
