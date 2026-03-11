class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        if(n == 1) return 0;
        int dummy = n;
        int bits = 0;
        while(dummy > 0) {
            dummy >>= 1;
            bits = bits == 0 ? 1 : bits * 2 + 1;
        }
        return bits ^ n;
    }
};
