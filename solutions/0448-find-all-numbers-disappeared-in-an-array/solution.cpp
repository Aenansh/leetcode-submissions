class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        unordered_map<int, int> mp;

        for (int n : nums)
            mp[n]++;

        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            if (mp.find(i) == mp.end())
                ans.push_back(i);
        }

        return ans;
    }
};
