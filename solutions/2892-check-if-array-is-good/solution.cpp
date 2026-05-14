class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int maxEl = nums[n - 1];
        if(maxEl + 1 != n) return false;

        if(nums[0] != 1) return false;
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] - 1 != nums[i - 1]) return false;
        }
        return nums[n - 1] == maxEl;
    }
};
