class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int ans = 0;
        int d = n;
        while(n >= 1){
            ans = (ans << 1) | 1;
            n = n >> 1;
        }
        return d ^ ans;
    }
};
