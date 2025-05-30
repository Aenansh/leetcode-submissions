class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        for (auto i : prerequisites) {
            graph[i[1]][i[0]] = 1;
        }
        vector<int> inDeg(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < numCourses; j++) {
                if (graph[j][i] == 1)
                    inDeg[i]++;
            }
        }
        queue<int> q;
        int res = 0;
        for (int i = 0; i < inDeg.size(); i++) {
            if (inDeg[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            res++;
            int curr = q.front();
            q.pop();
            for (int i = 0; i < numCourses; i++) {
                if (graph[curr][i] == 1) {
                    inDeg[i]--;
                    if (inDeg[i] == 0)
                        q.push(i);
                }
            }
        }
        return res == numCourses;
    }
};
