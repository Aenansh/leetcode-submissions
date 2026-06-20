class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int m = restrictions.size();
        if (m == 0)
            return n - 1;
        sort(begin(restrictions), end(restrictions));
        bool isLast = restrictions[m - 1][0] == n ? true : false;
        int len = m + 1 + (isLast ? 0 : 1);

        vector<vector<int>> pass(len, vector<int>(2));
        pass[0][0] = 1;
        pass[0][1] = 0;

        for (int i = 0; i < m; i++) {
            int diff = restrictions[i][0] - pass[i][0];
            int height = pass[i][1] + diff;
            pass[i + 1][0] = restrictions[i][0];
            pass[i + 1][1] = min(height, restrictions[i][1]);
        }

        if (!isLast) {
            int diff = n - pass[m][0];
            int ht = pass[m][1] + diff;
            pass[m + 1][0] = n;
            pass[m + 1][1] = min(ht, n - 1);
        }

        for (int i = len - 2; i >= 0; i--) {
            int diff = pass[i + 1][0] - pass[i][0];
            int ht = pass[i + 1][1] + diff;
            pass[i][1] = min(pass[i][1], ht);
        }

        int ans = 0;
        for (int i = 1; i < len; i++) {
            int left = pass[i - 1][0];
            int right = pass[i][0];
            int lH = pass[i - 1][1];
            int rH = pass[i][1];

            int mx = (right - left - abs(lH - rH)) / 2 + max(lH, rH);

            ans = max(ans, mx);
        }

        return ans;
    }
};
