class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMax = 0, currMin = 0;
        int ansMax = 0, ansMin = 0;

        for (int num : nums) {
            currMax = max(0, currMax + num);
            currMin = min(0, currMin + num);

            ansMax = max(ansMax, currMax);
            ansMin = min(ansMin, currMin);
        }
        return max(ansMax, abs(ansMin));
    }
};
