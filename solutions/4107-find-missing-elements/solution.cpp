class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(begin(nums), end(nums));

        int n = nums.size();
        for (int i = nums[0] + 1; i < nums[n - 1]; i++) {
            int L = 0, R = n - 1;
            int idx = -1;
            while (L <= R) {
                int M = L + (R - L) / 2;
                if (nums[M] == i) {
                    idx = M;
                    break;
                } else if (nums[M] < i)
                    L = M + 1;
                else
                    R = M - 1;
            }

            if (idx == -1)
                ans.push_back(i);
        }

        return ans;
    }
};
