class Solution {
    vector<vector<char>> rotate90(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> rotated(n, vector<char>(m));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rotated[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        return rotated;
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();

        for(int i = 0; i < m; i++) {
            int drop = n - 1;
            for(int j = n - 1; j >= 0; j--) {
                if(boxGrid[i][j] == '*') drop = j - 1;
                else if(boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][drop]);
                    drop--;
                }
            }
        }
        vector<vector<char>> r = rotate90(boxGrid);
        return r;
    }
};
