class Solution {
    int dp[301][27][27];

    pair<int, int> getPoints(int C) { return {C / 6, C % 6}; }

    int getDist(int F, int C) {
        auto [x1, y1] = getPoints(F);
        auto [x2, y2] = getPoints(C);
        return (abs(x1 - x2) + abs(y1 - y2));
    }

    int solve(string& word, int i, int f1, int f2) {
        if (i >= word.length())
            return 0;

        int result = 0;
        int curr = word[i] - 'A';

        if (dp[i][f1][f2] != -1)
            return dp[i][f1][f2];

        if (f1 == 26 && f2 == 26) {
            return dp[i][f1][f2] = solve(word, i + 1, curr, f2);
        }

        if (f2 == 26) {
            int moveF2 = solve(word, i + 1, f1, curr);
            int moveF1 = getDist(f1, curr) + solve(word, i + 1, curr, f2);
            return dp[i][f1][f2] = min(moveF2, moveF1);
        }

        int moveF1 = getDist(f1, curr) + solve(word, i + 1, curr, f2);
        int moveF2 = getDist(f2, curr) + solve(word, i + 1, f1, curr);

        return dp[i][f1][f2] = min(moveF1, moveF2);
    }

public:
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, 26, 26);
    }
};
