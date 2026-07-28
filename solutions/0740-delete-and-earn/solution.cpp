class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        map<int, int> mp;
        for (auto i : nums)
            mp[i]++;

        vector<int> uniques;
        for (auto [k, v] : mp) {
            uniques.push_back(k);
        }

        if(uniques.size() == 1) {
            return uniques[0] * mp[uniques[0]];
        }
        int a = mp[uniques[0]] * uniques[0];
        int b = -1;
        if (abs(uniques[0] - uniques[1]) > 1) {
            b = a + mp[uniques[1]] * uniques[1];
        } else
            b = max(a, mp[uniques[1]] * uniques[1]);

        for (int i = 2; i < uniques.size(); i++) {
            int temp = -1;
            if (uniques[i] - uniques[i - 1] == 1) {
                temp = max(mp[uniques[i]] * uniques[i] + a, b);
            } else {
                temp = b + mp[uniques[i]] * uniques[i];
            }
            a = b;
            b = temp;
        }

        return b;
    }
};
