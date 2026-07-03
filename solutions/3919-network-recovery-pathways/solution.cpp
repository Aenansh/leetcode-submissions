class Solution {
    bool check(int M, int n, long long k,
               unordered_map<int, vector<vector<int>>>& adj) {
        vector<long long> res(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        res[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > k)
                return false;
            if (node == n - 1)
                return true;
            if (res[node] < d)
                continue;

            for (auto& vec : adj[node]) {
                int ng = vec[0];
                int w = vec[1];

                if (w < M)
                    continue;

                if (d + w < res[ng]) {
                    res[ng] = d + w;
                    pq.push({d + w, ng});
                }
            }
        }
        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        unordered_map<int, vector<vector<int>>> adj;

        int L = INT_MAX, R = 0;
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (!online[u] || !online[v])
                continue;
            adj[u].push_back({v, w});
            L = min(L, w);
            R = max(R, w);
        }

        int answer = -1;

        while (L <= R) {
            int M = L + (R - L) / 2;
            if (check(M, n, k, adj)) {
                answer = M;
                L = M + 1;
            } else {
                R = M - 1;
            }
        }

        return answer;
    }
};
