class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> great(n, 1);
        great[0] = nums[0];
        for(int i = 1; i < n; i++) {
            great[i] = max(great[i - 1], nums[i]);
        }

        vector<int> prefixGcd(n, 0);
        for(int i = 0; i < n; i++) {
            prefixGcd[i] = gcd(nums[i], great[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;
        for(int i = 0, j = n - 1; i < j; i++, j--) {
            ans += (long long)gcd(prefixGcd[i], prefixGcd[j]);
        }
        return ans;
    }
};
