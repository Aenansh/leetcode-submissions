class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for(auto& edge : edges) {
            graph[edge[0]][edge[1]] = 1;
        }

        int champs = 0, ans = -1;
        for(int i = 0; i < n; i++) {
            int total = 0;
            for(int j = 0; j < n; j++) {
                if(graph[j][i] == 1) total++;
            }
            if(total == 0) {
                champs++;
                if(champs == 1) ans = i;
                else return -1;
            }
        }
        return ans;
    }
};
