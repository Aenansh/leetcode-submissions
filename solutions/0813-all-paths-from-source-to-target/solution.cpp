class Solution {
    void backtrack(vector<vector<int>>& graph, vector<vector<int>>& paths,
                   vector<int>& p, int n, int src) {
        if (src == n - 1) {
            paths.push_back(p);
            return;
        }
        if (graph[src].empty())
            return;

        for (int& nextNode : graph[src]) {
            p.push_back(nextNode);
            backtrack(graph, paths, p, n, nextNode);
            p.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> path;
        path.push_back(0);
        backtrack(graph, paths, path, n, 0);
        return paths;
    }
};
