class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasTri;
        pasTri.push_back({1});

        if(numRows == 1) return pasTri;

        pasTri.push_back({1, 1});
        
        for(int i = 2; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for(int j = 0; j < i - 1; j++) {
                row[j + 1] = pasTri[i - 1][j] + pasTri[i - 1][j + 1];
            }
            pasTri.push_back(row);
        }
        return pasTri;
    }
};
