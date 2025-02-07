class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        struct pair_hash {
            size_t operator()(const pair<int, int>& p) const {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
        };
        unordered_set<pair<int, int>, pair_hash> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    mp.insert({i,j});
                }
            }
        }

        for(auto c : mp){
            int i = c.first, j = c.second;
            for(int k = 0; k < m; k++){
                matrix[k][j] = 0;
            }
            for(int k = 0; k < n; k++){
                matrix[i][k] = 0;
            }
        }
    }
};
