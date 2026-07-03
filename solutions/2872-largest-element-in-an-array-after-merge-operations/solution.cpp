class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long maxAns = nums[n - 1];
        long long ans = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= ans) {
                ans += nums[i];
                maxAns = max(maxAns, ans);
            } else {
                if (nums[i] > maxAns)
                    maxAns = nums[i];
                ans = nums[i];
            }
        }
        return maxAns;
    }
};
