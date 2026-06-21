class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;

        int n = nums.size();
        int need = n / 3;

        vector<int> ans;
        for (int num : nums) {
            if (mp[num] > need) {
                ans.push_back(num);
                mp.erase(num);
            }
        }

        return ans;
    }
};
