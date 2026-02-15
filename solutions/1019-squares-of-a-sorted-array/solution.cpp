class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums[0] > 0) {
            for (int i = 0; i < nums.size(); i++)
                nums[i] *= nums[i];
            return nums;
        }

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= 0)
                r = mid - 1;
            else
                l = mid + 1;
        }
        vector<int> ans;
        int i = r, j = r + 1;
        while (i >= 0 && j < nums.size()) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                ans.push_back(nums[i] * nums[i]);
                i--;
            } else {
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        while(i >= 0) {
            ans.push_back(nums[i] * nums[i]);
            i--;
        }
        while(j < nums.size()) {
            ans.push_back(nums[j] * nums[j]);
            j++;
        }
        return ans;
    }
};
