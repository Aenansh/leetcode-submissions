class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    int left = dp[i][j - 1];
                    int top = dp[i - 1][j];
                    int diagnol = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min({left, top, diagnol});
                }
            }
        }

        int side = -1;
        for (auto v : dp) {
            side = max(side, *max_element(begin(v), end(v)));
        }

        return side * side;
    }
};
