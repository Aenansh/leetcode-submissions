class Solution {
public:
    string invert(string bits) {
        for(int i = 0; i < bits.length(); i++) {
            bits[i] = bits[i] == '1' ? '0' : '1';
        }
        return bits;
    }
    char findKthBit(int n, int k) {
        string sn = "0";
        for(int i = 2; i <= n; i++) {
            string in = invert(sn);
            reverse(in.begin(), in.end());

            sn = sn + "1" + in;
        }

        return sn[k - 1];
    }
};
