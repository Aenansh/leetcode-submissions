class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int mod = 1e9 + 7;

        for (int i = 0; i < m; i++) {
            long long l = queries[i][0], r = queries[i][1], v = queries[i][3],
                k = queries[i][2];

            for(int idx = l; idx <= r; idx += k) {
                long long a = (long long)nums[idx] * v;
                nums[idx] = (int)(a % mod);
            }
        }

        int ans = nums[0];
        for(int i = 1; i < n; i++) ans ^= nums[i];
        return ans;
    }
};
