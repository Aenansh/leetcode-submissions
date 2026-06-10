class Solution {
    void dfs(int start, int& minQuiet, int& quietNode, vector<bool>& visited,
             vector<vector<int>>& adj, vector<int>& quiet) {
        visited[start] = true;
        for (int neib : adj[start]) {
            if (!visited[neib]) {
                if (quiet[neib] < minQuiet) {
                    minQuiet = quiet[neib];
                    quietNode = neib;
                }
                dfs(neib, minQuiet, quietNode, visited, adj, quiet);
            }
        }
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for (auto edge : richer) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int minQuiet = quiet[i];
            int quietNode = i;
            vector<bool> visited(n, false);
            dfs(i, minQuiet, quietNode, visited, adj, quiet);
            ans[i] = quietNode;
        }
        return ans;
    }
};
