class Solution {
    bool compare(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }
    void transpose(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();
        for (int r = 0; r < 3; r++) {
            if (compare(mat, target))
                return true;
            transpose(mat);
            for (auto& i : mat)
                reverse(i.begin(), i.end());
        }
        return compare(mat, target);
    }
};
