class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target;
        }
        int k;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                k = i + 1;
                break;
            }
        }
        int low1 = 0, low2 = k, high1 = k - 1, high2 = nums.size() - 1;
        if (nums[low1] == target || nums[low2] == target ||
            nums[high1] == target || nums[high2] == target)
            return true;
        while (low1 <= high1 && low2 <= high2) {
            int mid1 = low1 + (high1 - low1) / 2;
            int mid2 = low2 + (high2 - low2) / 2;
            if (nums[mid1] == target)
                return true;
            else if (nums[mid1] < target)
                low1 = mid1 + 1;
            else
                high1 = mid1 - 1;
            if (nums[mid2] == target)
                return true;
            else if (nums[mid2] < target)
                low2 = mid2 + 1;
            else
                high2 = mid2 - 1;
        }
        return false;
    }
};
