class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        int L = intervals[0][0];
        int R = intervals[0][1];

        int count = n;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= L && intervals[i][1] <= R)
                count--;
            else {
                L = min(L, intervals[i][0]);
                R = max(R, intervals[i][1]);
            }
        }

        return count;
    }
};
