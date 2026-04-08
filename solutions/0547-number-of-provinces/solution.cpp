class Solution {
    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int n,
             int src) {
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (isConnected[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(isConnected, visited, n, i);
                provinces++;
            }
        }
        return provinces;
    }
};
