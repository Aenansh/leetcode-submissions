class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if(x <= 9) return true;
        string s = to_string(x);
        for (int i = 0, j = s.length() - 1;
             i < s.length() / 2, j >= s.length() / 2; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
