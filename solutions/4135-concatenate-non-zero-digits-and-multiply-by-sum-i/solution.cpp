class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0)
            return 0;
        if (n <= 9)
            return n * n;

        long long sum = 0;
        long long x = 0;

        while (n > 0) {
            long long dig = n % 10;
            sum = sum + dig;
            if (dig != 0) {
                x = x + dig;
                if (n > 0)
                    x = 1LL * x * 10;
            }
            n = n / 10;
        }

        long long rev = 0;
        while (x != 0) {
            long long dig = x % 10;
            rev = (rev * 10) + dig;
            x = x / 10;
        }
        return rev * sum;
    }
};
