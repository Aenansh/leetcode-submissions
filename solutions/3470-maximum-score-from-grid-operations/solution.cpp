class Solution {
    typedef long long ll;
    int n;
    ll dp[2][101][101];

    ll solve(bool prevTaken, int prevHeight, int col,
             const vector<vector<int>>& grid, const vector<vector<ll>>& pref) {
        if (col == n) {
            return 0;
        }

        if (dp[prevTaken][prevHeight][col] != -1) {
            return dp[prevTaken][prevHeight][col];
        }
        ll res = 0;
        for (int height = 0; height <= n; height++) {
            ll prevColScore = 0;
            ll currColScore = 0;
            if (col > 0 && !prevTaken && height > prevHeight) {
                prevColScore =
                    pref[col - 1][height] - pref[col - 1][prevHeight];
            }
            if (prevHeight > height) {
                currColScore = pref[col][prevHeight] - pref[col][height];
            }
            bool isTaken = (prevHeight > height);
            ll takeCurr = prevColScore + currColScore +
                          solve(isTaken, height, col + 1, grid, pref);
            ll skipCurr =
                prevColScore + solve(false, height, col + 1, grid, pref);

            res = max({res, takeCurr, skipCurr});
        }

        return dp[prevTaken][prevHeight][col] = res;
    }

public:
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        vector<vector<ll>> pref(n, vector<ll>(n + 1, 0));

        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                pref[col][row + 1] = pref[col][row] + grid[row][col];
            }
        }
        return solve(false, 0, 0, grid, pref);
    }
};
