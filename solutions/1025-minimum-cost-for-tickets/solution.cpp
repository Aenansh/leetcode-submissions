class Solution {
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& dp) {
        if (i >= days.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int s1 = i + 1;
        int s7 = upper_bound(begin(days), end(days), days[i] + 6) - begin(days);
        int s30 =
            upper_bound(begin(days), end(days), days[i] + 29) - begin(days);

        return dp[i] = min({solve(days, costs, s1, dp) + costs[0],
                            solve(days, costs, s7, dp) + costs[1],
                            solve(days, costs, s30, dp) + costs[2]});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(days, costs, 0, dp);
    }
};
