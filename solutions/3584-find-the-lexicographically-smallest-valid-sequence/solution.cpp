class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.length(), n = word2.length();

        vector<int> equals(m, 0);

        int i = m - 1, j = n - 1;
        int matches = 0;

        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                matches++;
                j--;
            }
            equals[i] = matches;
            i--;
        }

        vector<int> seq;

        i = 0, j = 0;
        bool powerUsed = false;

        while (i < m && j < n) {
            if (word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if (!powerUsed && i + 1 < m && equals[i + 1] >= n - j - 1) {
                seq.push_back(i);
                powerUsed = true;
                j++;
            }
            i++;
        }

        if (seq.size() == n)
            return seq;

        return {};
    }
};
