class Solution {
    int dp[101][2][101];

    int solve(vector<int>& piles, int i, int p, int m) {
        if (i >= piles.size())
            return 0;

        if (dp[i][p][m] != -1)
            return dp[i][p][m];

        int stones = 0;

        if (p == 0) {
            int maxStones = 0;
            for (int idx = 1; idx <= 2 * m && i + idx - 1 < piles.size();
                 idx++) {
                stones += piles[i + idx - 1];
                maxStones = max(maxStones,
                                stones + solve(piles, i + idx, 1, max(m, idx)));
            }

            return dp[i][p][m] = maxStones;
        }

        int minStones = 1e9;
        for (int idx = 1; idx <= 2 * m && i + idx - 1 < piles.size(); idx++) {
            minStones = min(minStones, solve(piles, i + idx, 0, max(m, idx)));
        }

        return dp[i][p][m] = minStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, 0, 1);
    }
};
