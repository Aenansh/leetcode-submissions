class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        int nonzero = 0;
        for (auto n : nums) {
            total_xor ^= n;
            if (n > 0)
                nonzero++;
        }
        if (total_xor != 0)
            return nums.size();
        if (nonzero == 0)
            return 0;
        return nums.size() - 1;
    }
};
