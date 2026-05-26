class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> seen;
        int sp = 0;
        for(char c : word) {
            if(c >= 65 && c <= 90) seen.insert(c);
        }

        for(char c : word) {
            if(c >= 97 && c <= 122) {
                if(seen.count(c - 32)) {
                    sp++;
                    seen.erase(c - 32);
                }
            }
        }
        return sp;
    }
};
