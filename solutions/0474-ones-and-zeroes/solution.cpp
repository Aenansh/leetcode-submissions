class Solution {
    int solve(vector<vector<int>>& counts, int m, int n, int i,
              vector<vector<vector<int>>>& dp) {
        if (i < 0)
            return 0;

        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        int skip = solve(counts, m, n, i - 1, dp);
        int take = -1e9;
        if (m >= counts[i][0] && n >= counts[i][1])
            take =
                solve(counts, m - counts[i][0], n - counts[i][1], i - 1, dp) +
                1;

        return dp[i][m][n] = max(skip, take);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>> counts(sz, vector<int>(2, 0));

        for (int i = 0; i < sz; i++) {
            int ones = count(begin(strs[i]), end(strs[i]), '1');
            int zeros = count(begin(strs[i]), end(strs[i]), '0');

            counts[i][0] = zeros, counts[i][1] = ones;
        }

        vector<vector<vector<int>>> dp(
            sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(counts, m, n, sz - 1, dp);
    }
};
