class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int evens = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0)
                evens++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (evens > 0)
                {
                    nums[i] = 0;
                    evens--;
                }
            else
                nums[i] = 1;
        }
        return nums;
    }
};
