class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> upperRow = matrix[0];

        int d[3] = {1, 0, -1};

        for (int i = 1; i < n; i++) {
            vector<int> currRow = matrix[i];
            for (int j = 0; j < n; j++) {
                int minFall = INT_MAX;
                for (int k = 0; k < 3; k++) {
                    int idx = j + d[k];
                    if (idx >= 0 && idx < n) {
                        minFall = min(minFall, upperRow[idx]);
                    }
                }
                currRow[j] += minFall;
            }
            upperRow = currRow;
        }

        return *min_element(begin(upperRow), end(upperRow));
    }
};
