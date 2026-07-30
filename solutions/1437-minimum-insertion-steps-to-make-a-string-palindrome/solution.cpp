class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        vector<int> upperRow(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            vector<int> currRow(n + 1, 0);

            for (int j = 1; j <= n; j++) {
                if (s[j - 1] == s[n - i]) {
                    currRow[j] = upperRow[j - 1] + 1;
                } else {
                    currRow[j] = max(currRow[j - 1], upperRow[j]);
                }
            }

            upperRow = currRow;
        }

        return n - upperRow.back();
    }
};
