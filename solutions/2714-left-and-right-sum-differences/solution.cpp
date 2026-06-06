class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n);
        int lSum = 0, rSum = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = abs(arr[i] - lSum);
            lSum += nums[i];
            arr[n - 1 - i] = abs(arr[n - 1 - i] - rSum);
            rSum += nums[n - 1 - i];
        }
        return arr;
    }
};
