class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited,
             vector<int>& reached) {
        visited[node] = true;
        for (int neib : adj[node]) {
            if (!visited[neib]) {
                reached.push_back(neib);
                dfs(neib, adj, visited, reached);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            vector<int> reached;
            dfs(i, adj, visited, reached);
            sort(begin(reached), end(reached));
            ans.push_back(reached);
        }
        return ans;
    }
};
