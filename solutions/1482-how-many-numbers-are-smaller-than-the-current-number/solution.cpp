class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        vector<int> sortt = nums;
        sort(begin(sortt), end(sortt));
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(sortt[i]) == mp.end())
                mp[sortt[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            ans[i] = mp[nums[i]];
        }

        return ans;
    }
};
