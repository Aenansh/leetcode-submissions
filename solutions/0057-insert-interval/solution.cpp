class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();

        sort(begin(intervals), end(intervals));
        vector<vector<int>> ans;
        int L = intervals[0][0], R = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(R >= intervals[i][0]) {
                L = min(L, intervals[i][0]);
                R = max(R, intervals[i][1]);
            }
            else {
                ans.push_back({L, R});
                L = intervals[i][0], R = intervals[i][1];
            }
        }
        ans.push_back({L, R});
        return ans;
    }
};
