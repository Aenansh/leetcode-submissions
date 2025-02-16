class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i - k >= 0 && i + k < nums.size()){
                if(nums[i - k] < nums[i] && nums[i + k] < nums[i]){
                    sum += nums[i];
                }
            }
            else if(i - k >= 0){
                if(nums[i - k] < nums[i]) sum += nums[i];
            }
            else if(i + k < nums.size()){
                if(nums[i + k] < nums[i]) sum += nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        return sum;
    }
};
