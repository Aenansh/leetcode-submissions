class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> deg(n + 1, 0);
        for (auto i : edges) {
            int u = i[0], v = i[1];
            deg[u]++, deg[v]++;
            if (deg[u] == n - 1)
                return u;
            if (deg[v] == n - 1)
                return v;
        }
        return -1;
    }
};
