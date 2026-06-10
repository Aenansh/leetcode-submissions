class Solution {
    int n;
    vector<int> parents;
    vector<int> size;

    int Find(int u) {
        if(u == parents[u]) return u;
        return parents[u] = Find(parents[u]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        parents.resize(n + 1);
        size.resize(n + 1, 1);
        iota(begin(parents), end(parents), 0);

        int au = -1, av = -1;

        for(auto edge : edges) {
            int u = edge[0], v = edge[1];
            int pu = Find(u);
            int pv = Find(v);

            if(pu == pv) {
                au = u, av = v;
            } else if(size[pu] >= size[pv]) {
                parents[pv] = pu;
                size[pu] += size[pv];
            } else {
                parents[pu] = pv;
                size[pv] += size[pu];
            }
        }

        return {au, av};
    }
};
