class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int max = nums[0];
        for (int i : nums) {
            if (i > max)
                max = i;
        }
        vector<int> cnt(max + 1, 0);
        for (int i : nums) {
            cnt[i]++;
        }
        for (int i = 1; i < cnt.size(); i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ans(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 0)
                ans[i] = 0;
            else {
                int val = cnt[nums[i] - 1];
                ans[i] = val;
            }
        }
        return ans;
    }
};
