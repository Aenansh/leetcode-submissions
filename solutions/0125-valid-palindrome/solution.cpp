class Solution {
public:
    bool isPalindrome(string s) {
        string k = "";
        for(auto i : s)
        {
            if(isalnum(i))
            k += tolower(i);
        }
        string r = k;
        reverse(k.begin(), k.end());
        if(k == r) return true;
        return false;
    }
};
