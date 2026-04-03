class Solution {
    vector<vector<int>> t;

    int countWalls(vector<int>& walls, int l, int r) {
        int left = lower_bound(begin(walls), end(walls), l) - begin(walls);
        int right = upper_bound(begin(walls), end(walls), r) - begin(walls);

        return right - left;
    }

    int solve(vector<int>& walls, vector<vector<int>>& rd,
              vector<vector<int>>& range, int i, int dir) {
        if (i == rd.size())
            return 0;
        if (t[i][dir] != -1)
            return t[i][dir];
        int left = range[i][0];
        if (dir == 1) {
            left = max(left, range[i - 1][1] + 1);
        }
        int leftTake = countWalls(walls, left, rd[i][0]) +
                       solve(walls, rd, range, i + 1, 0);
        int rightTake = countWalls(walls, rd[i][0], range[i][1]) +
                        solve(walls, rd, range, i + 1, 1);

        return t[i][dir] = max(rightTake, leftTake);
    }

public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        int m = walls.size();
        t.assign(n + 1, vector<int>(2, -1));
        vector<vector<int>> rd(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            rd[i][0] = robots[i];
            rd[i][1] = distance[i];
        }
        sort(begin(rd), end(rd));
        sort(begin(walls), end(walls));
        vector<vector<int>> range(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            int L = (i == 0) ? 1 : rd[i - 1][0] + 1;
            int R = (i == n - 1) ? 1e9 : rd[i + 1][0] - 1;
            range[i][0] = max(rd[i][0] - rd[i][1], L);
            range[i][1] = min(rd[i][0] + rd[i][1], R);
        }

        return solve(walls, rd, range, 0, 0);
    }
};
