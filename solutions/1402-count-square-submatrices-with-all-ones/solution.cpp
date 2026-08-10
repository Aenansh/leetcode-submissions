class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> upperRow = matrix[0];

        int count = accumulate(begin(upperRow), end(upperRow), 0);

        for (int i = 1; i < m; i++) {
            vector<int> currRow = matrix[i];
            count += currRow[0];

            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1)
                    currRow[j] +=
                        min({currRow[j - 1], upperRow[j], upperRow[j - 1]});
                count += currRow[j];
            }

            upperRow = currRow;
        }
        return count;
    }
};
