class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        digits[0] += 1;
        if (digits[0] > 9) {
            int i = 0;
            while (digits[i] > 9) {
                digits[i] %= 10;
                if (i == digits.size() - 1) {
                    digits.push_back(1);
                } else {
                    digits[++i] += 1;
                }
            }
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
