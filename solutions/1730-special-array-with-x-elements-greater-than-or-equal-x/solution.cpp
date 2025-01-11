class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i <= nums.size(); i++){
            int val = n - (lower_bound(nums.begin(), nums.end(), i) - nums.begin());
            if(val == i) return i;
        }
        return -1;
        
    }
};
