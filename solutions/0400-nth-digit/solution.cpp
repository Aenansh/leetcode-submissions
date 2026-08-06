class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, start = 1, size = 9;

        while (n > len * size) {
            n -= len * size;
            len++;
            size *= 10;
            start *= 10;
        }

        long long num = start + (n - 1) / len;

        string ans = to_string(num);

        return ans[(n - 1) % len] - '0';
    }
};
