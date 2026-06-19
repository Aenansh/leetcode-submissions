class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(begin(nums), end(nums));
        double small = numeric_limits<double>::max();

        int i = 0, j = nums.size() - 1;
        while (i < j) {
            double avg = (double)(nums[i++] + nums[j--]) / 2.0;
            small = min(small, avg);
        }
        return small;
    }
};
