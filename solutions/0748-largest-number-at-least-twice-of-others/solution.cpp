class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = -1;
        int lIdx = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largest) {
                largest = nums[i];
                lIdx = i;
            }
        }

        int ndLarge = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > ndLarge && nums[i] < largest) {
                ndLarge = nums[i];
            }
        }

        return largest >= 2 * ndLarge ? lIdx : -1;
    }
};
