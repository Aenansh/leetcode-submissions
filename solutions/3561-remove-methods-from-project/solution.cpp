class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (auto neib : adj[node]) {
            if (!visited[neib])
                dfs(neib, adj, visited);
        }
    }

public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto edge : invocations) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(n, false);
        dfs(k, adj, visited);

        vector<int> ans;
        int allGood = -1;
        for (auto edge : invocations) {
            int u = edge[0], v = edge[1];
            if (!visited[u] && visited[v]) {
                allGood = 1;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i] || allGood == 1)
                ans.push_back(i);
        }

        return ans;
    }
};
