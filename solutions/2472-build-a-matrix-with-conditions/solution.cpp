class Solution {
    void makeAdj(vector<vector<int>>& adj, vector<vector<int>> edges) {
        for (auto edge : edges) {
            adj[edge[0]][edge[1]] = 1;
        }
    }

    vector<int> topologicalSort(int k, vector<vector<int>> adj) {
        queue<int> q;
        vector<int> inDeg(k + 1, 0);
        vector<int> order;

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                inDeg[i] += adj[j][i];
            }
        }

        for (int i = 1; i <= k; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int neighbor = 1; neighbor <= k; neighbor++) {
                if (adj[node][neighbor]) {
                    inDeg[neighbor]--;
                    if (inDeg[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }
        return order.size() == k ? order : vector<int>();
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> rowAdj(k + 1, vector<int>(k + 1, 0));
        vector<vector<int>> colAdj(k + 1, vector<int>(k + 1, 0));
        makeAdj(rowAdj, rowConditions);
        makeAdj(colAdj, colConditions);

        vector<int> rowOrder = topologicalSort(k, rowAdj);
        vector<int> colOrder = topologicalSort(k, colAdj);

        if (rowOrder.empty() || colOrder.empty())
            return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < rowOrder.size(); i++) {
            int val = rowOrder[i];
            int j = 0;
            for (; j < colOrder.size(); j++) {
                if (colOrder[j] == val)
                    break;
            }
            matrix[i][j] = val;
        }

        return matrix;
    }
};
