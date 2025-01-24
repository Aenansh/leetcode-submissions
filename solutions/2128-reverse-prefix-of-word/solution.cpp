class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto iter = find(word.begin(), word.end(), ch);
        if(iter == word.end()) return word;
        int chPos = distance(word.begin(), iter);
        reverse(word.begin(), word.begin() + chPos + 1);
        return word;
    }
};
