class Solution {
public:
    int findMin(vector<int>& nums) {
        int m = nums[0];
        for(auto i : nums){
            m = min(m, i);
        }
        return m;
    }
};
