class Solution {
    bool checkWin(vector<string>& board, char p) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
                return true;
        }

        for (int i = 0; i < 3; i++) {
            if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
                return true;
        }

        if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
            return true;
        if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
            return true;

        return false;
    }

public:
    bool validTicTacToe(vector<string>& board) {
        int xcount = 0, ocount = 0;

        for (auto i : board) {
            for (auto c : i) {
                if (c == 'X')
                    xcount++;
                else if (c == 'O')
                    ocount++;
            }
        }

        if (ocount > xcount || xcount > ocount + 1)
            return false;

        bool xWins = checkWin(board, 'X');
        bool oWins = checkWin(board, 'O');

        if (xWins && oWins)
            return false;

        if (xWins && xcount != ocount + 1)
            return false;
        if (oWins && ocount != xcount)
            return false;
        return true;
    }
};
