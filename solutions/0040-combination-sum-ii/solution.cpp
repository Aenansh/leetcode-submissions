class Solution {
    void solve(vector<vector<int>>& combns, vector<int>& comb, vector<int>& arr, int t, int idx) {
        if(t == 0) {
            combns.push_back(comb);
            return;
        }
        for(int i = idx; i < arr.size(); i++) {
            if(i > idx && arr[i] == arr[i - 1]) continue;
            if(arr[i] > t) break;
            comb.push_back(arr[i]);
            solve(combns, comb, arr, t - arr[i], i + 1);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combns;
        vector<int> comb;
        sort(begin(candidates), end(candidates));
        solve(combns, comb, candidates, target, 0);
        return combns;
    }
};
