class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int i = 0;
        for(; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                res[0] = i;
                break;
            }
        }
        for(; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                res[1] = i;
            }
        }
        return res;
    }
};
