class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();

        int minTime = INT_MAX;

        for (int i = 0; i < m; i++) {
            int landFirst = landStartTime[i] + landDuration[i];
            for(int j = 0; j < n; j++) {
                int currCombo = landFirst;
                if(currCombo < waterStartTime[j]) {
                    currCombo += abs(waterStartTime[j] - currCombo);
                }
                minTime = min(minTime, currCombo + waterDuration[j]);
            }
        }

        for (int i = 0; i < n; i++) {
            int waterFirst = waterStartTime[i] + waterDuration[i];
            for(int j = 0; j < m; j++) {
                int currCombo = waterFirst;
                if(currCombo < landStartTime[j]) {
                    currCombo += abs(landStartTime[j] - currCombo);
                }
                minTime = min(minTime, currCombo + landDuration[j]);
            }
        }
        return minTime;
    }
};
