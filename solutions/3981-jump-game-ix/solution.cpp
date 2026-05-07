class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n);
        vector<int> suffMin(n);

        prefMax[0] = nums[0];
        suffMin[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
            suffMin[n - i - 1] = min(suffMin[n - i], nums[n - i - 1]);
        }

        vector<int> dp(n);
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if(i == n - 1 || prefMax[i] <= suffMin[i + 1]) {
                            int val = prefMax[i];
            for(int j = comp; j <= i; j++) {
                dp[j] = val;
            }
            comp = i + 1;
            }
        }
        return dp;
    }
};
