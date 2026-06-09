class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    adj[i][j] = 0;
            }
        }
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u][v] = w;
            adj[v][u] = w;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (adj[j][i] != 1e9 && adj[i][k] != 1e9) {
                        adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
                    }
                }
            }
        }

        int minCities = n + 1;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int totalCities = 0;
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= distanceThreshold && i != j)
                    totalCities++;
            }
            if (totalCities < minCities) {
                minCities = totalCities;
                ans = i;
            }
            else if(totalCities == minCities) ans = i;
        }
        return ans;
    }
};
