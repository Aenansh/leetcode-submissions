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
    int minimumDifference(vector<int>& nums, int k) {
        if (nums.size() == 1 || k == 1)
            return 0;
        if (!isSorted(nums))
            sort(nums.begin(), nums.end());
        int min = INT_MAX;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            int pos = i + k - 1;
            if (nums[pos] - nums[i] < min) {
                min = nums[pos] - nums[i];
            }
        }
        return min;
    }
};
