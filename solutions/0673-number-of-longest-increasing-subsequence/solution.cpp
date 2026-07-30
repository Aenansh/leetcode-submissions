class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp1[j] + 1 == dp1[i])
                        dp2[i] += dp2[j];
                    else if (dp1[j] + 1 > dp1[i]) {
                        dp1[i] = dp1[j] + 1;
                        dp2[i] = dp2[j];
                    }
                }
            }
        }

        int maxVal = *max_element(begin(dp1), end(dp1));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (dp1[i] == maxVal)
                cnt += dp2[i];
        }

        return cnt;
    }
};

