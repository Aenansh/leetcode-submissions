class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> mp;
        for (char c : s) {
            if (!mp.count(c))
                mp.insert(c);
        }
        string letter = "\0";
        for (char c : s) {
            if (c >= 'A' && c <= 'Z' && mp.count(c + 32) && c > letter[0]) {
                letter = c;
            }
        }
        return letter;
    }
};
