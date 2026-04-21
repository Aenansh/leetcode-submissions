class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u) {
        if (parent[u] == u)
            return parent[u];
        return parent[u] = find(parent[u]);
    }
    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU d(n);
        for (auto i : allowedSwaps) {
            d.unite(i[0], i[1]);
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[d.find(i)].push_back(i);
        }

        int ans = 0;

        for (auto& i : groups) {
            auto& idc = i.second;
            unordered_map<int, int> freq;

            for (int k : idc)
                freq[source[k]]++;

            for (int k : idc) {
                if (freq[target[k]] > 0) {
                    freq[target[k]]--;
                } else
                    ans++;
            }
        }
        return ans;
    }
};
