class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int cumSum = 0;
        mpp[0] = 1;

        long long validPointsLeft = 0, result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                validPointsLeft += mpp[cumSum];
                cumSum += 1;
            } else {
                cumSum -= 1;
                validPointsLeft -= mpp[cumSum];
            }

            mpp[cumSum] += 1;
            result += validPointsLeft;
        }

        return result;
    }
};
