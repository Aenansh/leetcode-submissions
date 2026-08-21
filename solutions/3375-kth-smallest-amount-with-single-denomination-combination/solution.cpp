class Solution {
    long long countSmaller(long long M, vector<int>& coins) {
        long long correctCount = 0;

        int n = coins.size();

        for (int i = 1; i <= (1 << n) - 1; i++) {
            long long order = 0;
            long long lcm = 0;

            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    order++;

                    if (lcm == 0) {
                        lcm = coins[j];
                    } else {
                        lcm = lcm * coins[j] / gcd(lcm, coins[j]);
                    }
                }
            }
            if (order % 2 == 0) {
                correctCount -= M / lcm;
            } else {
                correctCount += M / lcm;
            }
        }

        return correctCount;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long res = -1;

        long long L = 1;
        long long R = (long long)(*max_element(begin(coins), end(coins))) * k;

        while (L <= R) {
            long long M = L + (R - L) / 2;

            if (countSmaller(M, coins) >= k) {
                res = M;
                R = M - 1;
            } else {
                L = M + 1;
            }
        }

        return res;
    }
};
