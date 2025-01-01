class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int L = 0, R = (m * n) - 1;
        while(L <= R){
            int mid = (L + R) / 2;
            int i = mid / n;
            int j = mid % n;
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) L = mid + 1;
            else R = mid - 1;
        }
        return false;
    }
};
