class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            if (!mp[val])
                mp[val]++;
            else
                ans.push_back(val);
        }
        return ans;
    }
};
