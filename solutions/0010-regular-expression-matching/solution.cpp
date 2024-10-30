class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dpTable(n + 1, vector<bool>(m + 1, false));
        dpTable[0][0] = true;
        for(int row = 0; row <= n; row++)
        {
            for(int col = 1; col <= m; col++)
            {
                if(p[col - 1] != '*')
                {
                    dpTable[row][col] = row > 0 && (s[row - 1] == p[col-1] || p[col - 1] == '.') && dpTable[row - 1][col - 1];
                }
                else
                {
                    dpTable[row][col] = dpTable[row][col - 2] || ( row > 0 && (s[row-1] == p[col - 2] || p[col - 2] == '.') && dpTable[row - 1][col]); 
                }
            }
        }
        return dpTable[n][m];
    }
};
