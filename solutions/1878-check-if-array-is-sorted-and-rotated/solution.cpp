class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] < nums[i]) {
                idx = i + 1;
                break;
            }
        }
        if(idx == -1) return true;
        if(nums[idx] > nums[0]) return false;
        for(int j = idx + 1; j < n; j++) {
            if(nums[j] < nums[j - 1] || nums[j] > nums[0]) return false;
        }
        return true;
    }
};
