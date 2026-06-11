class Solution {
    int dfs(int root, int parent, vector<vector<int>>& adj) {
        int maxD = 0;
        for (int node : adj[root]) {
            if (node == parent)
                continue;
            maxD = max(maxD, 1 + dfs(node, root, adj));
        }
        return maxD;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        int mod = 1e9 + 7;
        vector<vector<int>> adj(n + 1);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int maxDepth = dfs(1, -1, adj);
        if(maxDepth == 0) return 0;
        long long ans = 1;
        for (int i = 0; i < maxDepth - 1; i++) {
            ans = (ans * 2) % mod;
        }

        return ans;
    }
};
