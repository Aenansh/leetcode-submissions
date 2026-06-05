class Solution {
    void backtrack(int n, int k, int& i, vector<bool>& visited, string p,
                   string& ans) {
        if (!ans.empty())
            return;
        if (p.length() == n) {
            i++;
            if (i == k) {
                ans = p;
            }
            return;
        }

        for (int idx = 1; idx <= n; idx++) {
            if (!visited[idx]) {
                p.push_back('0' + idx);
                visited[idx] = true;
                backtrack(n, k, i, visited, p, ans);
                p.pop_back();
                visited[idx] = false;
            }
        }
    }

public:
    string getPermutation(int n, int k) {
        string ans = "", p = "";
        int i = 0;
        vector<bool> visited(n + 1, false);
        backtrack(n, k, i, visited, p, ans);

        return ans;
    }
};
