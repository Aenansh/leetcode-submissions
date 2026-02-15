class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i = 0; i < points.size() - 1; i++) {
            int t1 = abs(points[i][0] - points[i + 1][0]);
            int t2 = abs(points[i][1] - points[i + 1][1]);
            time += max(t1, t2);
        }
        return time;
    }
};
