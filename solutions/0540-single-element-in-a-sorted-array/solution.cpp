class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0;
        if(nums.size() == 1)
        return nums[i];
        while(i < nums.size())
        {
            if(nums[i] != nums[i+1])
            {
                return nums[i];
            }
            else
            {
                i = i + 2;
            }
        }
        return -1;
    }
};
