class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> relaxed(n + 1, 0);
        int e = times.size();
        relaxed[k] = 1;
        int dis_cov = 0;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (true) {
            for (int i = 0; i < e; i++) {
                if (times[i][0] == k) {
                    dist[times[i][1]] =
                        min(dist[times[i][1]], times[i][2] + dis_cov);
                }
            }
            int minval = INT_MAX;
            int minInd = -1;
            for (int i = 1; i < dist.size(); i++) {
                if (minval > dist[i] && relaxed[i] == 0) { 
                    minval = dist[i];
                    minInd = i;
                }
            }
            if(minInd == -1) break;
            k = minInd;
            relaxed[k] = 1;
            dis_cov = dist[k];
        }

        int maxVal = INT_MIN;
        for(int i = 1; i < dist.size(); i++){
            if(maxVal < dist[i]) maxVal = dist[i];
        }

        return maxVal == INT_MAX ? -1 : maxVal;
    }
};
