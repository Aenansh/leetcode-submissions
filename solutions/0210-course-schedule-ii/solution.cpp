class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> res;
        for (int i = 0; i < inDeg.size(); i++) {
            if (inDeg[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (int i = 0; i < numCourses; i++) {
                if (graph[curr][i] == 1) {
                    inDeg[i]--;
                    if (inDeg[i] == 0)
                        q.push(i);
                }
            }
        }
        if(res.size() == numCourses) return res;
        return {};
    }
};
