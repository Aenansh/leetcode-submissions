class Solution {
    int solve(vector<int>& arr, int d, int i, int n, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];
        int jumps = 1, jumped = 1;

        for (int idx = i + 1; idx < n && idx <= i + d; idx++) {
            if (arr[idx] < arr[i]) {
                jumped = 1 + solve(arr, d, idx, n, dp);
                jumps = max(jumps, jumped);
            } else
                break;
        }

        for (int idx = i - 1; idx >= 0 && idx >= i - d; idx--) {
            if (arr[idx] < arr[i]) {
                jumped = 1 + solve(arr, d, idx, n, dp);
                jumps = max(jumps, jumped);
            } else
                break;
        }

        return dp[i] = jumps;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int val = solve(arr, d, i, n, dp);
            ans = max(ans, val);
        }
        return ans;
    }
};
