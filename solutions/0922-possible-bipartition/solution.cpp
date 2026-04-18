class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, 0);

        vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
        for (auto& edge : dislikes) {
            int r = edge[0];
            int c = edge[1];
            graph[r][c] = 1;
            graph[c][r] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (color[i])
                continue;

            color[i] = 1;
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int j = 1; j <= n; j++) {
                    if (!color[j] && graph[curr][j]) {
                        color[j] = 3 - color[curr];
                        q.push(j);
                    } else if (color[j] && color[j] == color[curr] && graph[curr][j])
                        return false;
                }
            }
        }
        return true;
    }
};
