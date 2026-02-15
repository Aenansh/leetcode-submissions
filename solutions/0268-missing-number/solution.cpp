class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x1 = 0;
        int x2 = 0;
        int n = nums.size();
        for (auto i : nums)
            x2 ^= i;
        for (int i = 0; i < n + 1; i++)
            x1 ^= i;
        return x1 ^ x2;
    }
};
