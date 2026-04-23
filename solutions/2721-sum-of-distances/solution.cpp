class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, long long> indexCount;
        unordered_map<int, long long> indexSum;

        for (int i = 0; i < n; i++) {
            long long freq = indexCount[nums[i]];
            long long sum = indexSum[nums[i]];

            ans[i] += freq * i - sum;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }

        indexCount.clear();
        indexSum.clear();

        for (int i = n - 1; i >= 0; i--) {
            long long freq = indexCount[nums[i]];
            long long sum = indexSum[nums[i]];

            ans[i] += sum - freq * i;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }

        return ans;
    }
};
