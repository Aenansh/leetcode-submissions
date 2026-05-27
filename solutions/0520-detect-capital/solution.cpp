class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        char initial = word[0];

        if (initial >= 'A' && initial <= 'Z') {
            bool allCap = true;
            bool allLow = true;
            for (int i = 1; i < n; i++) {
                if (word[i] >= 'a' && word[i] <= 'z')
                    allCap = false;
                else
                    allLow = false;
            }
            if (allCap || allLow)
                return true;
            return false;
        }

        for (int i = 1; i < n; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z')
                return false;
        }
        return true;
    }
};
