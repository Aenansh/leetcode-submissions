class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // int start = nums[0] > nums[abs(i - nums[i]) % nums.size()]
            //                 ? 0
            //                 : abs(i - nums[i]) % nums.size();
            int start = max(0, i - nums[i]);
            for (int j = start; j <= i; j++) {
                sum += nums[j];
            }
        }
        return sum;
    }
};
