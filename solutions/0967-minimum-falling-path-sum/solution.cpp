class Solution {
    int solve(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i,
              int j) {
        if (j < 0 || j >= matrix[0].size())
            return 1e9;
        if (i == (matrix.size() - 1))
            return matrix[i][j];

        if (dp[i][j] != 10005)
            return dp[i][j];

        int minf = 1e9;
        int db = solve(dp, matrix, i + 1, j);
        int dl = solve(dp, matrix, i + 1, j - 1);
        int dr = solve(dp, matrix, i + 1, j + 1);

        minf = matrix[i][j] + min({dl, dr, db});
        return dp[i][j] = minf;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 10005));
        int minf = 1e9;
        for (int i = 0; i < n; i++)
            minf = min(minf, solve(dp, matrix, 0, i));
        return minf;
    }
};
