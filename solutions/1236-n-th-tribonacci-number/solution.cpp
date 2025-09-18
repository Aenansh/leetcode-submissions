class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        int t0 = 0, t1 = 1, t2 = 1;
        for(int i = 0; i < n - 2; i++) {
            int temp1 = t2, temp2 = t1;
            t2 += t1 + t0;
            t1 = temp1;
            t0 = temp2;
        }
        return t2;
    }
};
