class Solution {
    bool isOdd(char n) { return (n - '0') % 2 != 0; }

public:
    string largestOddNumber(string num) {
        int n = num.length();
        if (isOdd(num[n - 1]))
            return num;

        for (int i = n - 2; i >= 0; i--) {
            if (isOdd(num[i])) {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};
