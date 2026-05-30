class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> rel;
        for (int i = 0; i < s.length(); i++) {
            char ch1 = s[i], ch2 = t[i];
            if (rel.find(ch1) == rel.end()) {
                rel[ch1] = ch2;
            } else if (rel.find(ch1) != rel.end() && rel[ch1] != ch2) {
                return false;
            }
        }
        rel.clear();
        for (int i = 0; i < s.length(); i++) {
            char ch1 = t[i], ch2 = s[i];
            if (rel.find(ch1) == rel.end()) {
                rel[ch1] = ch2;
            } else if (rel.find(ch1) != rel.end() && rel[ch1] != ch2) {
                return false;
            }
        }
        return true;
    }
};
