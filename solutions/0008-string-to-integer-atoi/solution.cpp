inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
}
inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         [](unsigned char ch) { return !std::isspace(ch); })
                .base(),
            s.end());
}
class Solution {
    string firstDigits(string s) {
        string ans = "";
        for (char c : s) {
            if (isdigit(c))
                ans += c;
            else
                break;
        }
        return ans;
    }
    string removeZeroes(string s) {
        int lzero = 0;
        for (char c : s) {
            if (c == '0')
                lzero++;
            else
                break;
        }
        if (lzero > 0)
            s.erase(0, lzero);
        return s;
    }

public:
    int myAtoi(string s) {
        string imin = "2147483648", imax = "2147483647";
        ltrim(s);
        rtrim(s);
        int sign = 0;
        if (s[0] == '-' || s[0] == '+') {
            sign = s[0] == '-' ? 1 : 0;
            s.erase(0, 1);
        }
        s = firstDigits(s);
        s = removeZeroes(s);
        if (s.length() > 10) {
            return sign == 0 ? INT_MAX : INT_MIN;
        }
        if (s.length() == 10) {
            if (sign == 0) {
                if (s >= imax)
                    return INT_MAX;
            } else {
                if (s >= imin)
                    return INT_MIN;
            }
        }
        int num = 0;
            for (int i = 0; i < s.length(); i++) {
                num *= 10;
                num += s[i] - '0';
            }
        if (sign == 1)
            num = -num;
        return num;
    }
};
