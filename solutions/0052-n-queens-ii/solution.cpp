class Solution {
    bool isValid(vector<vector<bool>>& chess, int n, int i, int j) {
        for (int idx = i - 1; idx >= 0; idx--) {
            if (chess[idx][j])
                return false;
        }
        int bj = j - 1;
        for (int idx = i - 1; idx >= 0; idx--) {
            if (bj >= 0 && chess[idx][bj])
                return false;
            bj--;
        }
        bj = j + 1;
        for (int idx = i - 1; idx >= 0; idx--) {
            if (bj < n && chess[idx][bj])
                return false;
            bj++;
        }
        return true;
    }
    void backtrack(vector<vector<bool>>& chess, int n, int& sols, int i) {
        if (i == n) {
            sols++;
            return;
        }
        for (int idx = 0; idx < n; idx++) {
            if (isValid(chess, n, i, idx)) {
                chess[i][idx] = true;
                backtrack(chess, n, sols, i + 1);
                chess[i][idx] = false;
            }
        }
    }

public:
    int totalNQueens(int n) {
        int sols = 0;
        vector<vector<bool>> chess(n, vector<bool>(n, false));
        backtrack(chess, n, sols, 0);
        return sols;
    }
};
