class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int a = nums[0], b = max(nums[0], nums[1]);

        int maxAns = INT_MIN;
        for (int i = 2; i < n; i++) {
            int now = max(nums[i] + a, b);
            a = b;
            b = now;
        }
        return b;
    }
};
