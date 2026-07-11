class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        iota(begin(parent), end(parent), 0);
        size.resize(n, 1);
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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        DSU d(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            d.unite(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, vector<int>> comps;
        for (int i = 0; i < n; i++) {
            int pr = d.find(i);
            comps[pr].push_back(i);
        }

        int totalComps = comps.size();

        for (auto [key, val] : comps) {
            int vsz = val.size() - 1;
            for (auto node : val) {
                if (adj[node].size() < vsz) {
                    totalComps--;
                    break;
                }
            }
        }
        return totalComps;
    }
};
