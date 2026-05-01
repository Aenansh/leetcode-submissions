class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(auto num : nums) totalSum += num;

        int firstPerm = 0;
        for(int i = 0; i < n; i++) {
            firstPerm += i * nums[i];
        }

        int maxAns = firstPerm;
        for(int i = n - 1; i > 0; i--) {
            firstPerm = firstPerm - ((n - 1) * nums[i]) + (totalSum - nums[i]);
            maxAns = max(maxAns, firstPerm);
        }
        return maxAns;
    }
};
