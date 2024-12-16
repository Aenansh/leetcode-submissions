class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0; i < k; i++){
            int small = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[small] > nums[j]){
                    small = j;
                } 
            }
            nums[small] *= multiplier;
        }
        return nums;
    }
};
