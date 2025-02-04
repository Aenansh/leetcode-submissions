class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];
        int maxsum = 0, sum = 0;
        sum = nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                sum += nums[i + 1];
                maxsum = max(maxsum, sum);
            } else {
                maxsum = max(maxsum, sum);
                sum = nums[i + 1];
            }
        }
        return maxsum;
    }
};
