class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;

        int n = nums.size();

        int dup = -1;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1)
                dup = nums[i];
        }

        for (int i = 1; i <= n; i++) {
            if (mp.find(i) == mp.end()) {
                return {dup, i};
            }
        }
        return {};
    }
};
