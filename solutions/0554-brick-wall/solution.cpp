class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<long long, int> count;
        for (auto& r : wall) {
            long long prefix = 0;
            for (int i = 0; i < r.size() - 1; i++) {
                prefix += r[i];
                count[prefix]++;
            }
        }
        int maxSame = 0;
        for(auto& [k, v] : count) {
            maxSame = max(maxSame, v);
        }
        return n - maxSame;
    }
};
