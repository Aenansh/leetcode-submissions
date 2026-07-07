class NumMatrix {
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix.resize(m, vector<int>(n, 0));

        prefix[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++) {
            prefix[i][0] = prefix[i - 1][0] + matrix[i][0];
        }
        for (int j = 1; j < n; j++) {
            prefix[0][j] = prefix[0][j - 1] + matrix[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] +
                               matrix[i][j] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int corner = 0;
        if (row1 - 1 >= 0 && col1 - 1 >= 0)
            corner = prefix[row1 - 1][col1 - 1];
        int left = 0;
        if (col1 - 1 >= 0)
            left = prefix[row2][col1 - 1];
        int top = 0;
        if (row1 - 1 >= 0)
            top = prefix[row1 - 1][col2];
        return prefix[row2][col2] + corner - top - left;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
