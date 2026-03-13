class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = 0, h = 0;
        while(true) {
            t = nums[t];
            h = nums[nums[h]];
            if(h == t) break;
        }

        int t2 = 0;
        while(true) {
            t2 = nums[t2];
            t = nums[t];
            if(t == t2) break;
        }
        return t;
    }
};
