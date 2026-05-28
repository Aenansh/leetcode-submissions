class Solution {
    int solve(vector<int>& denoms, int amount, int idx,
              vector<vector<int>>& dp) {
        if (idx < 0)
            return 0;
        if (idx == 0) {
            if (amount % denoms[0] == 0)
                return 1;
            return 0;
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTake = solve(denoms, amount, idx - 1, dp);
        int take = 0;
        if (denoms[idx] <= amount)
            take = solve(denoms, amount - denoms[idx], idx, dp);

        return dp[idx][amount] = notTake + take;
    }

public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> denoms;

        for (int i = 0; i < n; i++) {
            int amount = i + 1;
            int expWays = numWays[i];
            int currWays = solve(denoms, amount, denoms.size() - 1, dp);

            if (currWays < expWays) {
                if (currWays + 1 != expWays)
                    return {};
                denoms.push_back(amount);
            } else if (currWays > expWays) {
                return {};
            }
        }
        return denoms;
    }
};
