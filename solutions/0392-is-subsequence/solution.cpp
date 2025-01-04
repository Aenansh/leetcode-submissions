class Solution {
public:
    bool isSubsequence(string s, string t) {
        string chk = "";
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            for (; j < t.length(); j++) {
                if (t[j] == s[i]) {
                        chk += t[j];
                        j++;
                        break;
                }
            }
        }
        return s == chk;
    }
};
