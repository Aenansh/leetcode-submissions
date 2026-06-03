class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();

        int earlyLand = INT_MAX;
        for (int i = 0; i < m; i++) {
            earlyLand = min(earlyLand, landStartTime[i] + landDuration[i]);
        }

        int earliestLand = INT_MAX;
        for (int i = 0; i < n; i++) {
            int time = max(earlyLand, waterStartTime[i]) + waterDuration[i];
            earliestLand = min(earliestLand, time);
        }

        int earlyWater = INT_MAX;
        for (int i = 0; i < n; i++) {
            earlyWater = min(earlyWater, waterStartTime[i] + waterDuration[i]);
        }

        int earliestWater = INT_MAX;
        for (int i = 0; i < m; i++) {
            int time = max(earlyWater, landStartTime[i]) + landDuration[i];
            earliestWater = min(earliestWater, time);
        }
        return min(earliestLand, earliestWater);
    }
};
