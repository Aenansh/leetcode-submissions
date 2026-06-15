class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (size[pu] >= size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        DSU d(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) == mp.end())
                mp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i] - 1) != mp.end()) {
                d.Union(mp[nums[i]], mp[nums[i] - 1]);
            }
            if (mp.find(nums[i] + 1) != mp.end()) {
                d.Union(mp[nums[i]], mp[nums[i] + 1]);
            }
        }

        return *max_element(begin(d.size), end(d.size));
    }
};
