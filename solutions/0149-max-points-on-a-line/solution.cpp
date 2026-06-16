class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return n;

        int maxCount = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopes;
            int x1 = points[i][0], y1 = points[i][1];
            int currMax = 0;
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];

                int dx = x2 - x1, dy = y2 - y1;
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                string s = to_string(dy) + "/" + to_string(dx);
                slopes[s]++;
                currMax = max(currMax, slopes[s]);
            }
            maxCount = max(maxCount, currMax + 1);
        }
        return maxCount;
    }
};
