class Solution {
    void solve(vector<vector<int>>& combns, vector<int>& comb, vector<int>& arr,
               int t, int idx) {
        if (t == 0) {
            combns.push_back(comb);
            return;
        }
        if(t < 0) return;
        for (int i = idx; i < arr.size(); i++) {
            comb.push_back(arr[i]);
            solve(combns, comb, arr, t - arr[i], i);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combns;
        vector<int> comb;
        solve(combns, comb, candidates, target, 0);
        return combns;
    }
};
