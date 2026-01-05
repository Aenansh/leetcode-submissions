class Solution {
public:
    int power(int x, long long n, int mod) {
        if(n == 0) return 1;
        long long half = power(x, n / 2, mod);
        long long result = (half * half) % mod;
        if(n % 2 == 1) {
            result = (result * x) % mod;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        int MOD = 1000000007;

        long long evenPlaces = (n + 1) / 2;
        long long oddPlaces = n / 2;

        int ans = (1LL * power(5, evenPlaces, MOD) * power(4, oddPlaces, MOD)) % MOD;
        return ans;
    }
};
