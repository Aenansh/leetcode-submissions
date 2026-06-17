class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        long long len = 0;
        for (char c : s) {
            if (c == '*') {
                if (len > 0)
                    len--;
            } else if (c == '#')
                len = len * 2;
            else if (c == '%')
                continue;
            else
                len++;
        }

        if (k >= len)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') {
                len++;
            } else if (s[i] == '%') {
                k = len - k - 1;
            } else if (s[i] == '#') {
                len = len / 2;
                if (k >= len)
                    k = k - len;
            } else {
                len--;
            }

            if (k == len)
                return s[i];
        }
        return '.';
    }
};
