class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0, maxones = 0;

        for (auto n : nums) {
            if (n == 1)
                ones++;
            else {
                ones = 0;
            }
            maxones = max(maxones, ones);
        }
        return maxones;
    }
};
