class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        if (numRows == s.length())
            return s;
        int n = numRows;
        int m = s.length();

        vector<vector<char>> tb(n, vector<char>(m, ' '));

        int r = 0, c = 0, i = 0;
        while (i < m) {
            tb[r][c] = s[i];
            i++, r++;
            if (r >= n && i < m) {
                r = n - 2;
                while (r > 0 && i < m) {
                    c++;
                    tb[r][c] = s[i];
                    i++, r--;
                }
                c++;
            }
        }

        string ans = "";
        for (auto i : tb) {
            for (auto c : i) {
                if (isalpha(c) || c == '.' || c == ',')
                    ans += c;
            }
        }

        return ans;
    }
};
