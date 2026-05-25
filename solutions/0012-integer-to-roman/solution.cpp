unordered_map<int, char> sym = {{1, 'I'},   {5, 'V'},   {10, 'X'},  {50, 'L'},
                                {100, 'C'}, {500, 'D'}, {1000, 'M'}};

class Solution {
public:
    string intToRoman(int num) {
        vector<int> digits;
        int tens = 1;
        while (num > 0) {
            int d = num % 10;
            d = d * tens;
            tens = tens * 10;
            digits.push_back(d);
            num = num / 10;
        }
        reverse(begin(digits), end(digits));
        string ans = "";
        for (int n : digits) {
            string a = to_string(n);
            int len = a.length();
            int zeros = 1;
            for (int i = 0; i < len - 1; i++) {
                zeros *= 10;
            }
            if (sym[n]) {
                ans += sym[n];
            } else if (a[0] == '4' || a[0] == '9') {
                ans += sym[zeros];
                ans += sym[zeros + n];
            } else {
                if (a[0] > '5') {
                    ans += sym[zeros * 10 / 2];
                    n = n - (zeros * 10) / 2;
                }
                while (n > 0) {
                    ans += sym[zeros];
                    n = n - zeros;
                }
            }
        }
        return ans;
    }
};
