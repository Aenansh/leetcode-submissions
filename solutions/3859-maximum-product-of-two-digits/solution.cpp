class Solution {
    vector<int> getAllDigits(int n) {
        if (n == 0)
            return {0};
        vector<int> dig;
        while (n > 0) {
            dig.push_back(n % 10);
            n = n / 10;
        }
        return dig;
    }

public:
    int maxProduct(int n) {
        vector<int> digits = getAllDigits(n);

        sort(begin(digits), end(digits), greater<int>());

        return digits[0] * digits[1];
    }
};
