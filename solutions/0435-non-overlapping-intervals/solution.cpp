class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int R = intervals[0][1];
        int n = intervals.size();
        int count = 0;
        for (int i = 1; i < n; i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if (l < R) {
                count++;
                R = min(R, r);
            } else {
                R = r;
            }
        }

        return count;
    }
};

