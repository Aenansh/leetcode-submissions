class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int big = *max_element(nums.begin(), nums.end());

        vector<int> cnt(big + 1, 0);

        for(auto i : nums) cnt[i]++;
        for(int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
        vector<int> ans(nums.size(), 0);
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] == 0) continue;
            else ans[i] = cnt[nums[i] - 1];
        }
        return ans;
    }
};
