class Solution {
public:
    bool isSorted(vector<int> arr) {
        int i = 0, j = arr.size() - 1;
        while (i <= j) {
            if (arr[i + 1] < arr[i] || arr[j] < arr[j - 1])
                return false;
        }
        return true;
    }
    int minPairSum(vector<int>& nums) {
        if (nums.size() == 2)
            return nums[0] + nums[1];
        if (!isSorted(nums))
            sort(nums.begin(), nums.end());

        int max = INT_MIN, n = nums.size() - 1;
        for (int i = 0; i <= n / 2; i++) {
            int sum = nums[i] + nums[n - i];
            if (sum > max)
                max = sum;
        }
        return max;
    }
};
