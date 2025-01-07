class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size() == 1) return true;
        // if(nums[0] == 0) return false;
        int jumpInd = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0 && i < nums.size() - 1){
                if(jumpInd == i) return false;
            }
            if(jumpInd >= nums.size() - 1) return true;
            jumpInd = max(jumpInd, i + nums[i]); 
        }
        return false;
    }
};
