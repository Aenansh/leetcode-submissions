class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;
        for (int i = 0; i < word.length() - 1; i++) {
            if (word[i] != word[i + 1]) {
                char c = word[i];
                if (count > 9) {
                    while (count > 9) {
                        comp += '9';
                        comp += c;
                        count -= 9;
                    }
                }
                comp += to_string(count) + c;
                count = 1;
            } else {
                count++;
            }
        }
        char c = word[word.length() - 1];
        if (count > 9) {
            while (count > 9) {
                comp += '9';
                comp += c;
                count -= 9;
            }
        }
        comp += to_string(count) + c;
        return comp;
    }
};
