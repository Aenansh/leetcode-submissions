class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                v.push_back(matrix[j][i]);
            }
        }
        sort(v.begin(), v.end());
        return v[k - 1];
    }
};
