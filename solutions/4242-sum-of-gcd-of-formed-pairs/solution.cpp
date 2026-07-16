class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int mx = nums[0];
        vector<long long> res(n);

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            res[i] = 1LL * gcd(mx, nums[i]);
        }

        sort(begin(res), end(res));
        long long sum = 0;

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            sum += gcd(res[i], res[j]);
        }
        return sum;
    }
};
