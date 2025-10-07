class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        vector<vector<int>> pasTri;
        pasTri.push_back({1});
        pasTri.push_back({1, 1});
        for (int i = 2; i <= rowIndex; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = pasTri[i - 1][j - 1] + pasTri[i - 1][j];
            }
            pasTri.push_back(row);
        }
        return pasTri[pasTri.size() - 1];
    }
};
