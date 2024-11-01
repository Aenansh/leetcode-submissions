class Solution {
public:
    int fib(int n) {
        if(n < 1)
        {
            return 0;
        }
        else if(n == 1)
        {
            return 1;
        }
        int pre1 = 0, pre2 = 1, curr = 0;
        for(int i = 1; i < n; i++)
        {
            curr = pre1 + pre2;
            pre1 = pre2;
            pre2 = curr;
        }
        return curr;
    }
};
