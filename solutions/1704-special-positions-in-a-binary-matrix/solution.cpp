class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rows[i]++, cols[j]++;
                }
            }
        }

        int sp = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    if (rows[i] == 1 && cols[j] == 1)
                        sp++;
                    else
                        continue;
                }
            }
        }

        return sp;
    }
};
