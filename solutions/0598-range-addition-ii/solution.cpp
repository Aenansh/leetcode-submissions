class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_x = m, min_y = n;
        for (auto op : ops) {
            min_x = min(min_x, op[0]);
            min_y = min(min_y, op[1]);
        }
        return min_x * min_y;
    }
};
