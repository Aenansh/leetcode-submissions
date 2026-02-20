class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ksum = accumulate(nums.begin(), nums.begin() + k, 0);
        double maxavg = (double)ksum / (double)k;
        int left = 0;
        for (int i = k; i < nums.size(); i++) {
            ksum -= nums[left++];
            ksum += nums[i];
            double avg = (double)ksum / (double)k;
            maxavg = max(maxavg, avg);
        }
        return maxavg;
    }
};
