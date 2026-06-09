class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long minVal = (long long)(*min_element(begin(nums), end(nums)));
        long long maxVal = (long long)(*max_element(begin(nums), end(nums)));

        return (long long)((maxVal - minVal) * (long long)(k));
    }
};
