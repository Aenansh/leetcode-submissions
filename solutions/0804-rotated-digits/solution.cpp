class Solution {
    bool isValid(int n) {
        int validbit = 0;
        while (n > 0) {
            int d = n % 10;
            if (d == 3 || d == 4 || d == 7)
                return false;
            if (d == 2 || d == 5 || d == 6 || d == 9)
                validbit++;
            n = n / 10;
        }
        return validbit > 0;
    }

public:
    int rotatedDigits(int n) {
        int digits = 0;
        for (int i = 1; i <= n; i++) {
            if (isValid(i))
                digits++;
        }
        return digits;
    }
};
