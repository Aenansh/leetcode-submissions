class Solution {
    void solve(vector<vector<int>>& combns, vector<int>& comb, int k, int n,
               int idx) {
        if (comb.size() == k) {
            if (n == 0) {
                combns.push_back(comb);
            }
            return;
        }

        for(int i = idx; i <= 9; i++) {
            comb.push_back(i);
            solve(combns, comb, k, n - i, i + 1);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combns;
        vector<int> comb;
        solve(combns, comb, k, n, 1);
        return combns;
    }
};
