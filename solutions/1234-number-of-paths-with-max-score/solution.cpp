class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int MOD = 1e9 + 7;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dp1(m, vector<int>(n, -1));
        vector<vector<int>> dp2(m, vector<int>(n, 0));

        dp1[m - 1][n - 1] = 0;
        dp2[m - 1][n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (board[m - 1][i] == 'X' || dp1[m - 1][i + 1] == -1)
                continue;
            int val = board[m - 1][i] - '0';
            dp1[m - 1][i] = val + dp1[m - 1][i + 1];
            dp2[m - 1][i] = dp2[m - 1][i + 1];
        }

        for (int j = m - 2; j >= 0; j--) {
            if (board[j][n - 1] == 'X' || dp1[j + 1][n - 1] == -1)
                continue;
            int val = board[j][n - 1] - '0';
            dp1[j][n - 1] = val + dp1[j + 1][n - 1];
            dp2[j][n - 1] = dp2[j + 1][n - 1];
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (board[i][j] == 'X')
                    continue;
                int val =
                    max({dp1[i][j + 1], dp1[i + 1][j], dp1[i + 1][j + 1]});
                if (val == -1)
                    continue;
                if (board[i][j] == 'E')
                    dp1[i][j] = val;
                else
                    dp1[i][j] = val + (board[i][j] - '0');
                if (dp1[i][j + 1] == val)
                    dp2[i][j] = (dp2[i][j] + dp2[i][j + 1]) % MOD;
                if (dp1[i + 1][j] == val)
                    dp2[i][j] = (dp2[i][j] + dp2[i + 1][j]) % MOD;
                if (dp1[i + 1][j + 1] == val)
                    dp2[i][j] = (dp2[i][j] + dp2[i + 1][j + 1]) % MOD;
            }
        }

        return {dp1[0][0] == -1 ? 0 : dp1[0][0], dp2[0][0]};
    }
};
