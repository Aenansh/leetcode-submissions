class Solution {
    int digProd(int n) {
        int prod = 1;
        while (n > 0) {
            prod *= (n % 10);
            n = n / 10;
        }

        return prod;
    }

public:
    int smallestNumber(int n, int t) {
        if (n % 10 == 0)
            return n;

        int maxx = n + (10 - n % 10);

        for (int i = n; i <= maxx; i++) {
            int v = digProd(i);
            if (v % t == 0)
                return i;
        }

        return -1;
    }
};
