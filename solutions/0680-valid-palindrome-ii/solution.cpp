class Solution {
    bool isPalindrome(string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int n = s.length();
        if (n <= 2)
            return true;

        int L = 0, R = n - 1;
        while (L < R) {
            if (s[L] == s[R]) {
                L++, R--;
            } else {
                return isPalindrome(s, L + 1, R) || isPalindrome(s, L, R - 1);
            }
        }
        return true;
    }
};
