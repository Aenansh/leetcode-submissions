class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int count = 0;
        int n = nums.size();
        seen[0]++;
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            if (seen.find(totalSum - k) != seen.end())
                count += seen[totalSum - k];
            seen[totalSum]++;
        }
        return count;
    }
};
