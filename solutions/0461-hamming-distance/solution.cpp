class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x ^ y;
        int cnt = 0;
        while (XOR> 0) {
            cnt += XOR & 1 ? 1 : 0;
            XOR >>= 1;
        }
        return cnt;
    }
};
