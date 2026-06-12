class Solution {
    int MOD = 1e9 + 7;
    int cols, row, n;
    vector<vector<int>> ancestor;
    vector<int> depth;

    void dfs(int curr, int parent, vector<int>& depth,
            vector<vector<int>>& adj) {
        ancestor[curr][0] = parent;
        for (int child : adj[curr]) {
            if (child != parent) {
                depth[child] = depth[curr] + 1;
                dfs(child, curr, depth, adj);
            }
        }
    }
    void buildAncestorTable() {
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node <= n; node++) {
                if (ancestor[node][j - 1] != -1)
                    ancestor[node][j] = ancestor[ancestor[node][j - 1]][j - 1];
            }
        }
    }
    int findLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int k = depth[u] - depth[v];

        for (int j = 0; j < cols; j++) {
            if (k & (1 << j)) {
                u = ancestor[u][j];
            }
        }
        if (u == v)
            return u;

        for (int j = cols - 1; j >= 0; j--) {
            if (ancestor[u][j] == -1)
                continue;
            if (ancestor[u][j] != ancestor[v][j]) {
                u = ancestor[u][j];
                v = ancestor[v][j];
            }
        }

        return ancestor[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        n = edges.size() + 1;
        cols = log2(n) + 1;
        vector<vector<int>> adj(n + 1);

        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.resize(n + 1, 0);
        ancestor.resize(n + 1, vector<int>(cols, -1));
        dfs(1, -1, depth, adj);
        buildAncestorTable();

        vector<int> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % MOD;
        }
        vector<int> res;

        for (auto& query : queries) {
            int u = query[0], v = query[1];
            int lca = findLCA(u, v);
            int d = depth[u] + depth[v] - 2 * depth[lca];

            if (d == 0)
                res.push_back(0);
            else
                res.push_back(pow2[d - 1]);
        }

        return res;
    }
};
