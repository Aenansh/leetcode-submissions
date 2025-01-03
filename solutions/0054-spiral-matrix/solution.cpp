class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        if (matrix.size() == 1)
            return matrix[0];
        if (matrix[0].size() == 1) {
            for (int i = 0; i < matrix.size(); i++) {
                ans.push_back(matrix[i][0]);
            }
            return ans;
        }
        auto [bottom, right] =
            make_pair(matrix.size() - 1, matrix[0].size() - 1);
        int top = 0, left = 0;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
