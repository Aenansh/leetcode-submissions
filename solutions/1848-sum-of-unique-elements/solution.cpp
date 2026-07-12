class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        int sum = 0;
        for (auto [k, v] : mp) {
            if (v == 1)
                sum += k;
        }

        return sum;
    }
};
