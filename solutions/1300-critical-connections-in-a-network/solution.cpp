class Solution {
    void dfs(int child, int parent, vector<vector<int>>& adj,
             vector<int>& timeIn, vector<int>& low,
             vector<vector<int>>& bridges, vector<bool>& visited, int& count) {
        timeIn[child] = low[child] = count;
        visited[child] = true;

        for (auto neighbor : adj[child]) {
            if (neighbor == parent) {
                continue;
            } else if (visited[neighbor]) {
                low[child] = min(low[child], low[neighbor]);
            } else {
                count++;
                dfs(neighbor, child, adj, timeIn, low, bridges, visited, count);
                low[child] = min(low[child], low[neighbor]);
                if (timeIn[child] < low[neighbor]) {
                    bridges.push_back({neighbor, child});
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        int m = connections.size();
        vector<vector<int>> adj(n);
        for (auto edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> timeIn(n);
        vector<int> low(n);

        vector<vector<int>> bridges;
        vector<bool> visited(n, false);

        int count = 0;

        dfs(0, -1, adj, timeIn, low, bridges, visited, count);

        return bridges;
    }
};
