class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minsize = nums.size() + 1;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                minsize = min(minsize, i - left + 1);
                sum -= nums[left++];
            }
        }
        return minsize == nums.size() + 1 ? 0 : minsize;
    }
};
