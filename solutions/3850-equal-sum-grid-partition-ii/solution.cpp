class Solution {
    typedef long long ll;
    ll total = 0;

    bool checkHorCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> st;
        ll top = 0;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }
            ll bottom = (total - top);
            ll diff = top - bottom;

            if (diff == 0)
                return true;

            if (diff == (ll)grid[0][0])
                return true;
            if (diff == (ll)grid[0][n - 1])
                return true;
            if (diff == grid[i][0])
                return true;
            if (i > 0 && n > 1 && st.count(diff))
                return true;
        }
        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (auto& row : grid) {
            for (auto& num : row) {
                total += num;
            }
        }

        if (checkHorCuts(grid))
            return true;
        reverse(begin(grid), end(grid));
        if (checkHorCuts(grid))
            return true;

        reverse(begin(grid), end(grid));
        vector<vector<int>> trans(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                trans[j][i] = grid[i][j];
            }
        }

        if (checkHorCuts(trans))
            return true;
        reverse(begin(trans), end(trans));
        if (checkHorCuts(trans))
            return true;

        return false;
    }
};
