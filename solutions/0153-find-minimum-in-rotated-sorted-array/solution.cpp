class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int L = 0, R = n - 1;

        int first = nums[0];
        while(L <= R) {
            int M = L + (R - L) / 2;
            if(nums[M] >= first) L = M + 1;
            else if(nums[M] < first) R = M - 1;
        }
        int ans = (R + 1) % n;
        return nums[ans];
    }
};
