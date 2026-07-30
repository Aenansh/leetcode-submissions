class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> dp;

        int maxVal = -1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                if (dp.find(diff) == dp.end()) {
                    dp[diff] = vector<int>(n, 1);
                }

                dp[diff][i] = max(dp[diff][j] + 1, dp[diff][i]);
                maxVal = max(maxVal, dp[diff][i]);
            }
        }

        return maxVal;
    }
};
