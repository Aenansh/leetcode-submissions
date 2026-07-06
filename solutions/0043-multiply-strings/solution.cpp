class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int m = num1.length(), n = num2.length();
        string res(m + n, '0');

        if (m < n) {
            swap(num1, num2);
            swap(m, n);
        }
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));

        int carry = 0, mul = 0;
        for (int i = 0; i < m; i++) {
            int n1 = num1[i] - '0';
            int j = 0;
            for (j = 0; j < n; j++) {
                int n2 = num2[j] - '0';
                int val = (n1 * n2) + mul;
                mul = val / 10;
                val = val % 10;

                int addval = (int)(res[i + j] - '0') + val + carry;
                carry = addval / 10;
                addval = addval % 10;
                res[i + j] = addval + '0';
            }
            if (mul != 0)
                res[i + j] = ((int)(res[i + j] - '0') + mul) + '0';
            if (carry != 0)
                res[i + j] = ((int)(res[i + j] - '0') + carry) + '0';
            mul = 0;
            carry = 0;
        }
        while (res.back() == '0')
            res.pop_back();
        reverse(begin(res), end(res));
        return res;
    }
};
