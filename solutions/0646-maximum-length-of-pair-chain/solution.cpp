class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs),
             [&](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int n = pairs.size();

        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }

        return *max_element(begin(dp), end(dp));
    }
};
