class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), q = queries.size();
        unordered_map<int, vector<int>> vals;
        for (int i = 0; i < n; i++) {
            vals[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int query : queries) {
            int elm = nums[query];
            vector<int>& ids = vals[elm];

            int sz = ids.size();
            if (sz == 1) {
                ans.push_back(-1);
                continue;
            }
            int pos = lower_bound(begin(ids), end(ids), query) - begin(ids);
            int res = INT_MAX;

            int right = ids[(pos + 1) % sz];
            int d = abs(query - right);
            int circDist = n - d;
            res = min({res, d, circDist});

            int left = ids[(pos - 1 + sz) % sz];
            d = abs(query - left);
            circDist = n - d;
            res = min({res, d, circDist});

            ans.push_back(res);
        }
        return ans;
    }
};
