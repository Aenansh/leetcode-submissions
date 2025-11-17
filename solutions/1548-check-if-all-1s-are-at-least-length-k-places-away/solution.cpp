class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int space = 0;
        for(auto i : nums) {
            if(i == 1 && space <= 0) space = k;
            else if(i == 1 && space > 0) return false;
            else if(i == 0) space--;
        }
        return true;
    }
};
