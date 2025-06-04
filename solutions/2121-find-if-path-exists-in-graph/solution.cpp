class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination)
            return true;
        vector<vector<int>> graph(n);
        for (auto i : edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto i : graph[curr]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
                if (i == destination)
                    return true;
            }
        }
        return false;
    }
};
