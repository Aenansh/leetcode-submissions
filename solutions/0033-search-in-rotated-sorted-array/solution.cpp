class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int beg;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] > nums[i + 1]) {
        //         beg = i + 1;
        //         break;
        //     }
        // }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            return i;
        }
        return -1;
    }
};
