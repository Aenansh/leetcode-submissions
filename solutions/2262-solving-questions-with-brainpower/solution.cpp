class Solution {
    long long solve(vector<vector<int>>& questions, int i,
                    vector<long long>& dp) {
        if (i >= questions.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        long long skip = solve(questions, i + 1, dp);
        long long take = solve(questions, i + 1 + questions[i][1], dp) +
                         (long long)questions[i][0];

        return dp[i] = max(skip, take);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(questions, 0, dp);
    }
};
