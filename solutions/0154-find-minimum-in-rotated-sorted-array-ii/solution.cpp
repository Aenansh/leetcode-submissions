class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int L = 0, R = n - 1;

        int first = nums[0];
        while(L <= R) {
            int M = L + (R - L) / 2;
            if(nums[M] > nums[R]) {
                L = M + 1;
            }
            else if(nums[M] < nums[R]) {
                R = M;
            }
            else R--;
        }
        return nums[L];
    }
};
