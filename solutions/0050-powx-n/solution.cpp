class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return (double)1;

        if (n < 0) {
            x = (double)1 / x;
            n = abs(n); 
        }
        double half = myPow(x, n / 2); 
        if(n % 2 == 0)
        {
            half = half * half;
        }
        else
        {
            half = half * half * x;
        }
        return half;
    }
};
