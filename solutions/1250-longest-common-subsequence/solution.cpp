class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();

        vector<int> upperRow(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            vector<int> currRow(m + 1, 0);
            for (int j = 1; j <= m; j++) {
                if (text1[j - 1] == text2[i - 1]) {
                    currRow[j] = upperRow[j - 1] + 1;
                } else {
                    currRow[j] = max(upperRow[j], currRow[j - 1]);
                }
            }
            upperRow = currRow;
        }

        return upperRow.back();
    }
};
