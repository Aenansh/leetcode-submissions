class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subsum;
        int modulo = 1000000007;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum  = sum % modulo + nums[j]; 
                subsum.push_back(sum);
            }
        }
        sort(subsum.begin(), subsum.end());
        int sum = 0;
        for(int i = left - 1; i < right; i++){
            sum = sum % modulo + subsum[i] % modulo;
        }
        return sum % modulo;
    }
};
