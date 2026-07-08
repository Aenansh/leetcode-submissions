class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        int m = s.length();

        vector<long long> prefix(m, 0);
        vector<long long> nums(m, 0);
        vector<long long> pow10(m + 1, 1);
        vector<long long> noNonZero(m, 0);
        vector<int> ans;

        pow10[0] = 1;
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        prefix[0] = s[0] - '0';
        noNonZero[0] = s[0] != '0' ? 1 : 0;
        nums[0] = s[0] - '0';

        for (int i = 1; i < m; i++) {
            prefix[i] += prefix[i - 1] + (s[i] - '0');
            if (s[i] != '0') {
                nums[i] = (nums[i - 1] * 10 + (s[i] - '0')) % MOD;
                noNonZero[i] = noNonZero[i - 1] + 1;
            } else {
                nums[i] = nums[i - 1];
                noNonZero[i] = noNonZero[i - 1];
            }
        }

        for(auto q : queries) {
            int L = q[0], R = q[1];

            long long sum = prefix[R];
            long long x = nums[R];

            if(L - 1 >= 0) {
                sum -= prefix[L - 1];
                long long k = noNonZero[R] - noNonZero[L - 1];
                long long sub = (nums[L - 1] * pow10[k]) % MOD;
                x = (x - sub + MOD) % MOD;
            }

            long long val = (sum * x) % MOD;
            ans.push_back(val);
        }
        return ans;
    }
};
