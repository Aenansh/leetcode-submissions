class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n);
        for(auto road : roads) {
            deg[road[0]]++;
            deg[road[1]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({deg[i], i});
        }
        while(!pq.empty()) {
            auto [d, i] = pq.top();
            pq.pop();
            deg[i] = n;
            n--;
        }
        long long total = 0;
        for(auto road : roads) {
            total = total + (long long)(deg[road[0]] + deg[road[1]]);
        }
        return total;
    }
};
