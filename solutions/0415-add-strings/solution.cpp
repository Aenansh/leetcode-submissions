class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        int carry = 0;
        while (i >= 0 || j >= 0) {
            int A = 0, B = 0;
            if (i >= 0)
                A = num1[i--] - '0';
            if (j >= 0)
                B = num2[j--] - '0';
            int s = A + B + carry;
            if (s > 9) {
                s = s % 10;
                carry = 1;
            } else
                carry = 0;
            sum += '0' + s;
        }
        if (carry == 1)
            sum += '1';
        reverse(begin(sum), end(sum));
        return sum;
    }
};
