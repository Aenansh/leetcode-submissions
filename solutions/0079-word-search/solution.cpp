class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited,
                   string word, int ind, int r, int c) {
        if (ind == word.length())
            return true;

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[ind] || visited[r][c]) {
            return false;
        }
        visited[r][c] = true;
        bool res = backtrack(board, visited, word, ind + 1, r + 1, c) ||
                   backtrack(board, visited, word, ind + 1, r, c + 1) ||
                   backtrack(board, visited, word, ind + 1, r, c - 1) ||
                   backtrack(board, visited, word, ind + 1, r - 1, c);
        
        visited[r][c] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, visited, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};  
