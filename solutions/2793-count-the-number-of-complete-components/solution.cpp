class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
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
        DSU obj(n);
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            obj.Union(u, v);
        }

        unordered_map<int, vector<int>> comps;
        for (int i = 0; i < n; i++) {
            int root = obj.Find(i);
            comps[root].push_back(i);
        }
        
        int totalComps = comps.size();

        for(auto [key, val] : comps) {
            int vsize = val.size() - 1;
            if(adj[key].size() < vsize) totalComps--;
            else {
                for(int node : val) {
                    if(adj[node].size() < vsize) {
                        totalComps--;
                        break;
                    }
                }
            }
        }
        return totalComps;
    }
};
