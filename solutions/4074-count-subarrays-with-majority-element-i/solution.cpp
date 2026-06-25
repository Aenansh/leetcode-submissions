class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            mpp[nums[i]]++;
            if (nums[i] == target)
                count++;
            int maxC = mpp[nums[i]], maxE = nums[i];
            for (int j = i + 1; j < n; j++) {
                mpp[nums[j]]++;
                if (mpp[nums[j]] > maxC) {
                    maxC = mpp[nums[j]];
                    maxE = nums[j];
                }
                if (maxE == target && 2 * maxC > (j - i + 1))
                    count++;
            }
        }

        return count;
    }
};
