class Solution {
public:
    int findMin(vector<int>& nums) {
        // int low = 0, high = nums.size() - 1;
        // while(low <= high)
        // {
        //     int mid = low + (high - low) / 2;
        //     if(nums[mid] > nums[mid + 1]) return nums[mid + 1];
        //     else if(nums[mid] < nums[mid - 1]) return nums[mid];

        // }
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};
