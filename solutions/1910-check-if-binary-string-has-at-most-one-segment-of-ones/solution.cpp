class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int seg = 0, ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                ones++;
            else {
                if (ones > 0) {
                    seg++;
                    ones = 0;
                }
            }
        }
        if (ones > 0)
            seg += 1;
        return seg == 1;
    }
};
