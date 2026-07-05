class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;

        int count = n - 2;
        for (long long p = 2; p < n; p++) {
            if (primes[p]) {
                for (long long i = p * p; i < n; i += p) {
                    if(primes[i]) {
                        primes[i] = false;
                        count--;
                    }
                }
            }
        }
        return count;
    }
};
