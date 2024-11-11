class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 0)
        return;
        int zco = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                i--;
                zco++;
            }
        }
        for(int i = 0; i < zco; i++)
        {
            nums.push_back(0);
        }
    }
};
