class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int x = 0, y = 0, maxDis = 0, dir = 0;
        unordered_set<long long> obs;
        for (auto& i : obstacles) {
            long long hashVal = (long long)(i[0] + 30000) * 100000LL + (i[1] + 30000);
            obs.insert(hashVal);
        }

        for (auto& c : commands) {
            if (c == -1)
                dir = (dir + 1) % 4;
            else if (c == -2)
                dir = (dir + 3) % 4;
            else {
                for (int i = 1; i <= c; i++) {
                    int cur_x = x + dx[dir];
                    int cur_y = y + dy[dir];
                    long long a = (long long)(cur_x + 30000) * 100000LL + (cur_y + 30000);
                    if (obs.count(a)) {
                        break;
                    }
                    x = cur_x, y = cur_y;
                    maxDis = max(maxDis, ((x * x) + (y * y)));
                }
            }
        }
        return maxDis;
    }
};
