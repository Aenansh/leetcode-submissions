class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        // FIX 1: Use assignment (=) for Path Compression
        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int x_p = find(x);
        int y_p = find(y);
        if (x_p == y_p)
            return false;

        if (rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;
        } else if (rank[x_p] < rank[y_p]) {
            parent[x_p] = y_p;
        } else {
            parent[x_p] = y_p;
            // FIX 2: Increment the rank, not the parent
            rank[y_p]++; 
        }
        return true;
    }
};

class Solution {
public:
    bool check(int n, vector<vector<int>>& edges, int k, int mid) {
        DSU dsu(n);
        vector<vector<int>> upd;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int m = edge[3];

            if (m == 1) {
                if (s < mid)
                    return false;
                dsu.Union(u, v);
            } else {
                if (s >= mid) {
                    dsu.Union(u, v);
                } else if (2 * s >= mid) {
                    upd.push_back({u, v});
                }
            }
        }

        for (auto& edge : upd) {
            int u = edge[0];
            int v = edge[1];
            if (dsu.find(u) != dsu.find(v)) {
                if (k <= 0)
                    return false;
                dsu.Union(u, v);
                k--;
            }
        }

        int root = dsu.find(0);
        for (int node = 1; node <= n - 1; node++) {
            if (dsu.find(node) != root) 
                return false;
        }
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int m = edge[3]; // Cleaned up unused 's' variable

            if (m == 1) {
                // If mandatory edges form a cycle, they are redundant but 
                // typically don't invalidate the graph unless strictly required by the problem.
                // Assuming your original logic is what the problem demands!
                if (dsu.find(u) == dsu.find(v))
                    return -1; 
                dsu.Union(u, v);
            }
        }

        int result = -1;
        int l = 1;
        int r = 200000; // FIX 3: Replaced 2 * 1e5 to avoid double-to-int conversion issues
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(n, edges, k, mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};
