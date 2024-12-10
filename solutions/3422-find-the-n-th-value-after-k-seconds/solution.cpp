class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<long long> nums(n, 1);
        for(int i = 1; i <= k; i++){
            for(int j = 1; j < nums.size(); j++){
                nums[j] = (nums[j] + nums[j - 1]) % MOD; 
            }
        }
        return nums[nums.size() - 1] % MOD;
    }
};
