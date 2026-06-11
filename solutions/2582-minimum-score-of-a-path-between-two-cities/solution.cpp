class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n + 1, 1);
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
    int minScore(int n, vector<vector<int>>& roads) {
        DSU d(n);
        for(auto road : roads) {
            d.Union(road[0], road[1]);
        }
        int pr = d.Find(1);
        int minDis = INT_MAX;

        for(auto road : roads) {
            int w = road[2];
            int u = road[0];
            if(d.Find(u) == pr) {
                minDis = min(w, minDis);
            }
        }
        return minDis;
    }
};
