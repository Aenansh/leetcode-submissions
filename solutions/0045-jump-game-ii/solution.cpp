class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curr_end = 0, farthest = 0;
        for(int i = 0; i < n - 1; i++) {
            farthest = max(farthest, nums[i] + i);
            if(i == curr_end) {
                curr_end = farthest;
                jumps++;
            }
        }

        return jumps;
    }
};
