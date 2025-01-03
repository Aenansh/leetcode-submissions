class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        long long leftsum = 0;
        long long rightsum = 0;
        for (auto i : nums)
            rightsum += i;

        for (int i = 0; i < nums.size() - 1; i++) {
            leftsum += nums[i];
            rightsum -= nums[i];
            if (leftsum >= rightsum) {
                count++;
            }
        }
        return count;
    }
};
