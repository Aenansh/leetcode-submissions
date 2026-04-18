class DSU {
public:
    vector<int> parent, rank;
    int extra;

    DSU(int n) {
        extra = 0;
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            extra++;
        else if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU d(n);
        for (auto& edge : connections) {
            d.unionRank(edge[0], edge[1]);
        }

        int comps = 0;
        for (int i = 0; i < n; i++) {
            if (d.parent[i] == i)
                comps++;
        }

        return d.extra >= comps - 1 ? comps - 1 : -1;
    }
};
