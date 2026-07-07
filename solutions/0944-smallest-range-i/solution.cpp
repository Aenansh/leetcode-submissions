class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        if(nums.size() == 1) return 0;
        int minn = *min_element(begin(nums), end(nums));
        int maxn = *max_element(begin(nums), end(nums));

        if(k == 0) return maxn - minn;
        if(2 * k >= maxn - minn) return 0;

        return (maxn - k) - (minn + k);
    }
};
