class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dpTable(n + 1, vector<int>(m + 1, 0));
        for(int row = 1; row <= n; row++)
        {
            for(int col = 1; col <= m; col++)
            {
                if(text1[row - 1] == text2[col - 1])
                {
                    dpTable[row][col] = 1 + dpTable[row - 1][col - 1];
                }
                else
                {
                    dpTable[row][col] = max(dpTable[row][col - 1], dpTable[row - 1][col]);
                }
            }
        }
        return dpTable[n][m];
    }
};
