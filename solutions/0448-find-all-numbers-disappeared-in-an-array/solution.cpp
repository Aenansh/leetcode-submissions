class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;
        for (int i = 1; i <= n; i++) {
            if (!mp[i])
                ans.push_back(i);
        }
        return ans;
    }
};
