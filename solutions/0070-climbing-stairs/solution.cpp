class Solution {
public:
    int climbStairs(int n) {
        if(n < 1)
        {
            return 0;
        }
        else if(n <= 2)
        {
            return n;
        }
        int k = 1, m = 2, sum = 0;
        for(int i = 3; i <= n; i++)
        {
            sum = k + m;
            k = m;
            m = sum;
        }
        return sum;
    }
};
