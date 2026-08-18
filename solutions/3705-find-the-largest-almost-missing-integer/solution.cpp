class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (auto i : nums)
            mp[i]++;

        int maxVal = -1;

        for (auto [k, v] : mp) {
            if (v == 1) {
                maxVal = max(maxVal, k);
            }
        }

        if (k == 1)
            return maxVal;

        if (k == n)
            return *max_element(begin(nums), end(nums));

        bool first = mp[nums[0]] == 1;
        bool second = mp[nums[n - 1]] == 1;

        if (first && second)
            return max(nums[0], nums[n - 1]);
        else if (first)
            return nums[0];
        else if(second)
            return nums[n - 1];

        return -1;
    }
};
