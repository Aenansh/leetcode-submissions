class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums), greater<int>());
        int sum = accumulate(begin(nums), end(nums), 0);
        vector<int> ans;

        int subsum = 0;

        for (int i = 0; i < n; i++) {
            subsum += nums[i];
            ans.push_back(nums[i]);
            if (subsum > sum - subsum)
                break;
        }

        return ans;
    }
};
