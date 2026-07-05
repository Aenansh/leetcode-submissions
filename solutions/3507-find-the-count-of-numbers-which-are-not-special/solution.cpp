class Solution {
    vector<bool> sieve(int r) {
        vector<bool> primes(r + 1, true);
        primes[0] = false;
        primes[1] = false;

        for (int p = 2; p * p <= r; p++) {
            if (primes[p]) {
                for (int i = p * p; i <= r; i += p) {
                    primes[i] = false;
                }
            }
        }
        return primes;
    }

public:
    int nonSpecialCount(int l, int r) {
        int sl = ceil(sqrt(l));
        int sr = sqrt(r);

        vector<bool> primes = sieve(sr);
        int count = 0;
        int i = sl;
        while (i < primes.size()) {
            if (primes[i])
                count++;
            i++;
        }

        int total = r - l + 1;
        return total - count;
    }
};
