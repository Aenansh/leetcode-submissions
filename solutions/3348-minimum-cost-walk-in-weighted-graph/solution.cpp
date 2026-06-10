class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        iota(begin(parent), end(parent), 0);
        size.resize(n, 1);
    }
    int Find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = Find(parent[u]);
    }
    void Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) return;
        if(size[pu] >= size[pv]) {
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU obj(n);
        for(auto edge : edges) {
            obj.Union(edge[0], edge[1]);
        }
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto edge : edges) {
            int w = edge[2];
            int root = obj.Find(edge[0]);
            if(mp.find(root) == mp.end()) mp[root] = w;
            else mp[root] &= w;
        }

        for(auto q : query) {
            int ru = obj.Find(q[0]), rv = obj.Find(q[1]);
            if(ru != rv) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(mp[ru]);
            }
        }
        return ans;
    }
};
