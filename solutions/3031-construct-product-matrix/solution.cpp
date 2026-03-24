class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> p(m, vector<int>(n));

        long long suff = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                p[i][j] = suff;
                suff = (suff * grid[i][j]) % mod;
            }
        }
        long long pref = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                p[i][j] =(pref * p[i][j]) % mod;
                pref = (pref * grid[i][j]) % mod;
            }
        }
        return p;
    }
};
