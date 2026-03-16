class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        unordered_set<int> res;
        priority_queue<int, vector<int>, greater<int>> pq;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(grid[i][j]);
                int t = i - 1, l = j - 1, r = j + 1, b = i + 1;
                while (t >= 0 && t < m && b >= 0 && b < m && l >= 0 && l < n &&
                       r >= 0 && r < n) {
                    int sum = 0;
                    for (int d1 = t, d2 = j; d1 <= i, d2 <= r; d1++, d2++) {
                        sum += grid[d1][d2];
                    }
                    for (int d1 = t, d2 = j; d1 <= i, d2 >= l; d1++, d2--) {
                        sum += grid[d1][d2];
                    }
                    for (int d1 = b, d2 = j; d1 >= i, d2 >= l; d1--, d2--) {
                        sum += grid[d1][d2];
                    }
                    for (int d1 = b, d2 = j; d1 >= i, d2 <= r; d1--, d2++) {
                        sum += grid[d1][d2];
                    }
                    sum = sum - (grid[t][j] + grid[i][r] + grid[i][l] + grid[b][j]);
                    t--, b++, l--, r++;
                    pq.push(sum);
                }
            }
        }
        while (!pq.empty()) {
            res.insert(pq.top());
            pq.pop();
        }
        vector<int> ans(res.begin(), res.end());
        sort(ans.begin(), ans.end(), greater<int>());
        if(ans.size() < 3) return ans;
        ans.resize(3);
        return ans;
    }
};
