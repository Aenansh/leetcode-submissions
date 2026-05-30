class Solution {
public:
    string toLowerCase(string s) {
        int n = s.length();
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch >= 'A' && ch <= 'Z') {
                ch = ch + 32;
                s[i] = ch;
            }
        }
        return s;
    }
};
