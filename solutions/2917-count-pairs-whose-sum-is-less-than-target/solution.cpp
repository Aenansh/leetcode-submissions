class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int L = i + 1, R = n - 1;
            while (L <= R) {
                int M = L + (R - L) / 2;
                if (nums[M] + nums[i] < target) {
                    L = M + 1;
                } else {
                    R = M - 1;
                }
            }

            count += (R - i);
        }

        return count;
    }
};
