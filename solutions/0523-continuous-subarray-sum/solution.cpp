class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<long long, int> mp;
        long long prefix = 0;

        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % k;
            if (mp.find(prefix) != mp.end()) {
                if (i - mp[prefix] >= 2)
                    return true;
            }
            else {
                mp[prefix] = i;
            }
        }

        return false;
    }
};
