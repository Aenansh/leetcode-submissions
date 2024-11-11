class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int check = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == check)
            {
                nums.erase(nums.begin() + i);
                i--;
            }
            else
            {
                check = nums[i];
            }
        }
        return nums.size();
    }
};
