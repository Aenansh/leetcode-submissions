class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        iota(begin(parent), end(parent), 0);
    }
    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (size[pu] >= size[pv]) {
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        DSU d(n);
        for (int i = 0; i < n - 1; i++) {
            if (abs(nums[i + 1] - nums[i]) <= maxDiff) {
                d.unite(i, i + 1);
            }
        }

        int m = queries.size();
        vector<bool> res(m, false);
        for (int i = 0; i < m; i++) {
            int u = queries[i][0], v = queries[i][1];
            if (d.find(u) == d.find(v))
                res[i] = true;
        }

        return res;
    }
};
