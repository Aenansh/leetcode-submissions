class Solution {
    int rows, cols;
    vector<vector<int>> anc;

    int customUpperBound(vector<vector<int>>& adj, int t) {
        int n = adj.size();
        int L = 0, R = n - 1;
        int res = 0;

        while (L <= R) {
            int M = L + (R - L) / 2;

            if (adj[M][0] <= t) {
                res = M;
                L = M + 1;
            } else
                R = M - 1;
        }
        return res;
    }

public: 
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> adj(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            adj[i][0] = nums[i];
            adj[i][1] = i;
        }
        sort(begin(adj), end(adj));

        vector<int> nodeToIdx(n);
        for (int i = 0; i < n; i++) {
            int idx = adj[i][1];
            nodeToIdx[idx] = i;
        }

        rows = n;
        cols = log2(n) + 1;

        anc.resize(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            int farthestHop = customUpperBound(adj, adj[i][0] + maxDiff);
            anc[i][0] = farthestHop;
        }

        for (int i = 1; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                anc[j][i] = anc[anc[j][i - 1]][i - 1];
            }
        }

        vector<int> res;

        for (auto q : queries) {
            int u = q[0], v = q[1];

            int a = nodeToIdx[u], b = nodeToIdx[v];
            if (a == b) {
                res.push_back(0);
                continue;
            }

            if (a > b) {
                swap(a, b);
            }

            int curr = a;
            int jumps = 0;

            for (int j = cols - 1; j >= 0; j--) {
                if (anc[curr][j] < b) {
                    curr = anc[curr][j];
                    jumps += (1 << j);
                }
            }

            if (anc[curr][0] >= b) {
                res.push_back(jumps + 1);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
