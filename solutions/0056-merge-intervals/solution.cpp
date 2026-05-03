class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));

        int L = intervals[0][0], R = intervals[0][1];

        vector<vector<int>> ans;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= R)
                R = max(R, intervals[i][1]);
            else {
                ans.push_back({L, R});
                L = intervals[i][0], R = intervals[i][1];
            }
        }
        ans.push_back({L, R});
        return ans;
    }
};
