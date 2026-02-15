class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[0] > 0)
                break;
            for (int j = i + 1; j < n; j++) {
                if (j - 1 > i && nums[j] == nums[j - 1])
                    continue;
                int t = -(nums[i] + nums[j]);
                if (mp.count(t) && mp[t] > j)
                    ans.push_back({nums[i], nums[j], nums[mp[t]]});
            }
        }
        return ans;
    }
};
