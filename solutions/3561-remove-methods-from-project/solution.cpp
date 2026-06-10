class Solution {
    void dfs(int node, vector<vector<int>>& adj, unordered_set<int>& sus,
             vector<bool>& visited) {
        visited[node] = true;
        sus.insert(node);
        for (auto neib : adj[node]) {
            if (!visited[neib]) {
                dfs(neib, adj, sus, visited);
            }
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

        unordered_set<int> sus;
        vector<bool> visited(n, false);
        dfs(k, adj, sus, visited);

        vector<int> ans;
        for (auto edge : invocations) {
            int u = edge[0], v = edge[1];
            if (!sus.count(u) && sus.count(v)) {
                ans.resize(n);
                iota(begin(ans), end(ans), 0);
                return ans;
            }
        }
        for(int i = 0; i < n; i++) {
            if(!sus.count(i)) ans.push_back(i);
        }
        return ans;
    }
};
