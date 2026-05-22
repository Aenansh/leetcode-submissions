class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0, R = n - 1;

        while (L <= R) {
            int M = L + (R - L) / 2;
            if (nums[M] == target)
                return M;

            if (nums[L] <= nums[M]) {
                if (target < nums[M] && target >= nums[L])
                    R = M - 1;
                else
                    L = M + 1;
            } else {
                if (target > nums[M] && target <= nums[R])
                    L = M + 1;
                else
                    R = M - 1;
            }
        }
        return -1;
    }
};
