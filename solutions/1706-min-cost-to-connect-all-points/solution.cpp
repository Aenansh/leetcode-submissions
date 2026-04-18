class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        int minCost = 0;
        int connected = 0;

        pq.push({0, 0});
        while (!pq.empty() && connected < n) {
            auto [wt, node] = pq.top();
            pq.pop();
            if (!visited[node]) {
                minCost += wt;
                visited[node] = true;
                connected++;
                for (int i = 0; i < n; i++) {
                    if (!visited[i]) {
                        int dis = (abs(points[node][0] - points[i][0]) +
                                   abs(points[node][1] - points[i][1]));
                        pq.push({dis, i});
                    }
                }
            }
        }
        return minCost;
    }
};
