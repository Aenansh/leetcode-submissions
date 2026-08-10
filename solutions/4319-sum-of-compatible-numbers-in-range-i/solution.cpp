class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for (int x = max(n - k, 1); x <= k + n; x++) {
            if ((n & x) == 0)
                sum += x;
        }
        return sum;
    }
};
