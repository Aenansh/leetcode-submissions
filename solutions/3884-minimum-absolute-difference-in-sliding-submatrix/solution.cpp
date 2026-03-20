class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i < m - k + 1; i++) {
            for (int j = 0; j < n - k + 1; j++) {
                unordered_set<int> s;
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        s.insert(grid[r][c]);
                    }
                }
                vector<int> urow(s.begin(), s.end());
                if (urow.size() <= 1)
                    res[i][j] = 0;
                else {
                    int mindiff = INT_MAX;
                    sort(urow.begin(), urow.end());
                    for (int t = 1; t < urow.size(); t++) {
                        mindiff = min(mindiff, abs(urow[t] - urow[t - 1]));
                    }
                    res[i][j] = mindiff;
                }
            }
        }
        return res;
    }
};
