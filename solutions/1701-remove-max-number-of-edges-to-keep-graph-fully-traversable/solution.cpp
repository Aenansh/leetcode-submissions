class DSU {
public:
    vector<int> parent;
    vector<int> size;
    int comps;
    DSU(int n) {
        parent.resize(n + 1);
        iota(begin(parent), end(parent), 0);
        size.resize(n + 1, 1);
        comps = n;
    }
    int Find(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = Find(parent[u]);
    }
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) {
            return false;
        }
        if (size[pu] >= size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        comps--;
        return true;
    }
    bool isSingle() { return comps == 1; }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);

        int kept = 0;
        for (auto edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            if (type == 3) {
                bool k1 = alice.Union(u, v);
                bool k2 = bob.Union(u, v);
                if (k1 || k2)
                    kept++;
            }
        }
        for (auto edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            if (type == 2) {
                bool k = bob.Union(u, v);
                if(k) kept++;
            } else {
                bool k = alice.Union(u, v);
                if(k) kept++;
            }
        }
        if (!alice.isSingle() || !bob.isSingle())
            return -1;

        return edges.size() - kept;
    }
};
