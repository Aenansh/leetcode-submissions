class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        auto [m, n] = make_pair(mat.size(), mat[0].size());
        if ((m == r && n == c) || (m * n != r * c))
            return mat;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int track_r = 0;
        int track_c = 0;
        for (auto i : mat) {
            for (auto j : i) {
                if(track_c == c && track_r == r) break;
                else if (track_c == c && track_r < r) {
                    track_c = 0;
                    track_r++;
                }
                ans[track_r][track_c] = j;   
                track_c++;
            }
        }
        return ans;
    }
};
