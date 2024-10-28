class Solution {
public:
    int reverse(int x) {
        int original = x; 
        long sum = 0;
        while (x != 0) {
            sum += x % 10;
            x /= 10;
            if (x != 0) {
                if (sum*10 >= INT_MAX || sum*10 <= INT_MIN) {
                    return 0;
                }
            sum *= 10;
            }
        }
        return sum;
    }
};
