class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> deg(n + 1, vector<int>(2, 0));

        for (auto i : trust) {
            int ind1 = i[0], ind2 = i[1];
            deg[ind1][0] += 1;
            deg[ind2][1] += 1;
        }

        for (int i = 1; i <= n; i++) {
            if (deg[i][0] == 0 && deg[i][1] == n - 1)
                return i;
        }
        return -1;
    }
};
