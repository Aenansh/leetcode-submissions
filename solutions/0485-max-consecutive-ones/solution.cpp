class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int maxOnes = 0;

        for (int i : nums) {
            if (i == 1) {
                ones++;
            } else {
                maxOnes = max(maxOnes, ones);
                ones = 0;
            }
        }

        maxOnes = max(maxOnes, ones);
        return maxOnes;
    }
};
