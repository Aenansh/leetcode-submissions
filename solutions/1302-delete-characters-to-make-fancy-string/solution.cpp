class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3)
            return s;
        string fancy = "";
        char c = '\0';
        for (int i = 0; i < s.length(); i++) {
            if (c != s[i]) {
                c = s[i];
                fancy += c;
            } else {
                if (i < 2)
                    fancy += c;
                else {
                    if (fancy[fancy.length() - 2] != c) {
                        fancy += c;
                    }
                }
            }
        }
        return fancy;
    }
};
