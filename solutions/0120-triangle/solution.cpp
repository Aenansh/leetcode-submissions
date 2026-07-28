class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> upperRow = triangle[0];

        for (int i = 1; i < n; i++) {
            vector<int> currRow = triangle[i];

            for (int j = 0; j < currRow.size(); j++) {
                int sum1 = INT_MAX;
                int sum2 = INT_MAX;
                if (j < upperRow.size())
                    sum1 = upperRow[j];
                if (j - 1 >= 0)
                    sum2 = upperRow[j - 1];
                currRow[j] += min(sum1, sum2);
            }
            upperRow = currRow;
        }

        return *min_element(begin(upperRow), end(upperRow));
    }
};
