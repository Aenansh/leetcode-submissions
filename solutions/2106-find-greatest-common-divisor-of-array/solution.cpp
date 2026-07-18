class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxVal = *max_element(begin(nums), end(nums));
        int minVal = *min_element(begin(nums), end(nums));

        return gcd(maxVal, minVal);
    }
};
