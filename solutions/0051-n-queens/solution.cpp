class Solution {
    bool isValid(vector<string>& chess, int n, int row, int col) {
        int r = row - 1, c = col;
        while (r >= 0) {
            if (chess[r][c] == 'Q')
                return false;
            r--;
        }
        r = row - 1, c = col - 1;
        while (r >= 0 && c >= 0) {
            if (chess[r][c] == 'Q')
                return false;
            r--, c--;
        }
        r = row - 1, c = col + 1;
        while (r >= 0 && c < n) {
            if (chess[r][c] == 'Q')
                return false;
            r--, c++;
        }
        return true;
    }

    void backtrack(vector<vector<string>>& chessBoards, vector<string>& chess,
                   int n, int row) {
        if (row == n) {
            chessBoards.push_back(chess);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(chess, n, row, col)) {
                chess[row][col] = 'Q';
                backtrack(chessBoards, chess, n, row + 1);
                chess[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> chessBoards;
        vector<string> chess(n, string(n, '.'));

        backtrack(chessBoards, chess, n, 0);

        return chessBoards;
    }
};
