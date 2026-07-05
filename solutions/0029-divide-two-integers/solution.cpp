class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1)
            return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN)
                return INT_MAX;
            else
                return -dividend;
        }
        int signbit = 0;
        if (divisor < 0)
            signbit = !signbit;
        if (dividend < 0)
            signbit = !signbit;

        long long dv = dividend, ds = divisor;
        if(dividend < 0) dv = -(long long)(dividend);
        if(divisor < 0) ds = -(long long)(divisor);

        long long count = 0;
        while (dv >= ds) {
            dv -= ds;
            count++;
        }
        if (signbit)
            count = -count;
        if (count < INT_MIN)
            return INT_MIN;
        return count > INT_MAX ? INT_MAX : count;
    }
};
