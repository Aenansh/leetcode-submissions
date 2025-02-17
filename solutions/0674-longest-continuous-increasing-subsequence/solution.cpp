class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxsize = 1, size = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] < nums[i + 1]){
                size++;
                maxsize = max(maxsize, size);
            }
            else
            size = 1;
        }
        return maxsize;
    }
};
