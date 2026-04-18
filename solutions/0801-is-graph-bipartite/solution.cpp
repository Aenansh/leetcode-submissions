class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {
            if(color[i]) continue;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                int adjColor = color[curr] == 1 ? 2 : 1;

                for (int next : graph[curr]) {
                    if (!color[next]) {
                        color[next] = adjColor;
                        q.push(next);
                    } else {
                        if (color[next] == color[curr])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
