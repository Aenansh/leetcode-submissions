class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        long long minAns = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[left] + nums[right];
                if (sum == target)
                    return sum;
                long long currDiff = (long long)abs(sum - target);
                long long diff = (long long)abs(minAns - target);
                if (currDiff < diff) {
                    minAns = sum;
                }
                if(sum < target) left++;
                else right--;
            }
        }
        return minAns;
    }
};
