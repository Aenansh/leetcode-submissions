class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int> lis;
        vector<int> dp(n, 1);

        lis.push_back(obstacles[0]);
        for (int i = 1; i < n; i++) {
            auto idx = upper_bound(begin(lis), end(lis), obstacles[i]) - begin(lis);
            if (idx < lis.size()) {
                lis[idx] = obstacles[i];
            } else {
                lis.push_back(obstacles[i]);
            }
            dp[i] = idx + 1;
        }

        return dp;
    }
};
