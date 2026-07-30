class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        vector<int> dp(n, 1);
        unordered_map<int, int> mp;
        mp[arr[0]] = 0;

        for (int i = 1; i < n; i++) {
            int t = arr[i] - difference;
            if (mp.find(t) != mp.end()) {
                dp[i] = max(dp[mp[t]] + 1, dp[i]);
            }
            mp[arr[i]] = i;
        }

        return *max_element(begin(dp), end(dp));
    }
};
