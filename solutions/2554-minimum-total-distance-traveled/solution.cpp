class Solution {
    long long dp[101][10005];

    long long getDist(int x, int y) {
        long long dist = (long long)(abs(x - y));
        return dist;
    }

    long long solve(vector<int>& robot, vector<int>& factory, int i, int j) {
        if (i >= robot.size())
            return 0;
        if (j >= factory.size())
            return 1e15;

        if(dp[i][j] != -1) return dp[i][j];
        
        long long take = getDist(robot[i], factory[j]) + solve(robot, factory, i + 1, j + 1);
        long long skip = solve(robot, factory, i, j + 1);

        return dp[i][j] = min(take, skip);
    }

public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> fact;
        for (int i = 0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos = factory[i][0];
            for (int j = 0; j < limit; j++)
                fact.push_back(pos);
        }

        memset(dp, -1, sizeof(dp));
        return solve(robot, fact, 0, 0);
    }
};
