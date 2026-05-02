class Solution {
    bool intersects(int x1, int y1, int x2, int y2) {
        return x2 >= x1 && x2 <= y1 || x1 >= x2 && x1 <= y2;
    }

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (intersects(firstList[i][0], firstList[i][1],
                               secondList[j][0], secondList[j][1])) {
                    int start = max(firstList[i][0], secondList[j][0]);
                    int end = min(firstList[i][1], secondList[j][1]);
                    ans.push_back({start, end});
                } 
            }
        }
        return ans;
    }
};
