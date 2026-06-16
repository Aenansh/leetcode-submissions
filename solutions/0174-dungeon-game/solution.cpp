class Solution {
    int solve(vector<vector<int>>& dungeon, int i, int j,
              vector<vector<int>>& dp) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        if (i >= m || j >= n)
            return 1e9;

        if (i == m - 1 && j == n - 1)
            return dungeon[i][j] <= 0 ? abs(dungeon[i][j]) + 1 : 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(dungeon, i, j + 1, dp);
        int down = solve(dungeon, i + 1, j, dp);

        int minHealth = min(right, down);

        int currHealth = minHealth - dungeon[i][j];
        if (currHealth <= 0)
            currHealth = 1;

        return dp[i][j] = currHealth;
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dungeon, 0, 0, dp);
    }
};
