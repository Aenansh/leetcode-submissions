class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if (rows == 1 || n <= 1)
            return encodedText;
        int cols = n / rows;
        vector<vector<char>> mat(rows, vector<char>(cols, ' '));
        int r = 0, c = 0;
        for (int i = 0; i < n; i++) {
            mat[r][c++] = encodedText[i];
            if (c == cols) {
                c = 0;
                r++;
            }
            if (r == rows)
                break;
        }
        string ans = "";
        r = 0, c = 0;
        while (r + c < cols) {
            ans += mat[r][c + r];
            r++;
            if (r == rows) {
                r = 0, c++;
            }
        }
        while(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};
