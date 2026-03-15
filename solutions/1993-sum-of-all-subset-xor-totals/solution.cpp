class Solution {
    void backtrack(int& res, int& Xor, vector<int>& nums, int index) {
        if (index == nums.size()) {
            res += Xor;
            return;
        }
        Xor ^= nums[index];
        backtrack(res, Xor, nums, index + 1);
        Xor ^= nums[index];
        backtrack(res, Xor, nums, index + 1);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int Xor = 0;
        backtrack(res, Xor, nums, 0);
        return res;
    }
};
