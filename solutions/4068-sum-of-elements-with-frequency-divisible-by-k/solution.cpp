class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        int sum = 0;

        for (auto [key, v] : mp) {
            if (v % k == 0)
                sum += key * v;
        }
        return sum;
    }
};
