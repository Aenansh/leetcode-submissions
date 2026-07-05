class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int sum1 = INT_MAX;
                int sum2 = INT_MAX;
                if (j < triangle[i - 1].size())
                    sum1 = triangle[i - 1][j];
                if (j - 1 >= 0)
                    sum2 = triangle[i - 1][j - 1];
                triangle[i][j] += min(sum1, sum2);
            }
        }

        return *min_element(begin(triangle[n - 1]), end(triangle[n - 1]));
    }
};
