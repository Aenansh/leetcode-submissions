class Solution {
    unordered_map<int, int> factors;
    void primeFactors(int n) {
        while(n % 2 == 0) {
            n = n / 2;
            factors[2]++;
        }

        for(int i = 3; i * i <= n; i += 2) {
            while(n % i == 0) {
                n = n / i;
                factors[i]++;
            }
        }

        if(n > 2) factors[n]++;
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        for(int n : nums) {
            primeFactors(n);
        }

        return factors.size();
    }
};
