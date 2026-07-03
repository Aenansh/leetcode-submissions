class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> occ;
        for (int i = 0; i < n; i++) {
            if (s[i] == c)
                occ.push_back(i);
        }

        int idx = 0;
        vector<int> answer(n, -1);

        for (int i = 0; i < n; i++) {
            int dis = abs(i - occ[idx]);
            if (idx + 1 < occ.size() && abs(i - occ[idx + 1]) < dis) {
                dis = abs(i - occ[idx + 1]);
                idx++;
            }
            answer[i] = dis;
        }
        return answer;
    }
};
