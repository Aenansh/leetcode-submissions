class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string s = "";
        while(x != 0)
        {
            s += to_string(x%10);
            x /= 10;
        }
        string k = s;
        reverse(s.begin(), s.end());
        if(k == s) return true;
        return false;
    }
};
