class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxLen = 0;
        unordered_map<string, bool> mp;
        for (auto word : wordDict) {
            int len = word.length();
            maxLen = max(maxLen, len);
            mp[word] = true;
        }

        int n = s.length();
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < maxLen; j++) {
                if (i - j >= 0 && mp[s.substr(i - j, j + 1)] == true) {
                    if (i - j >= 0) {
                        dp[i + 1] = dp[i - j];
                    } else
                        dp[i + 1] = true;
                    if (dp[i + 1])
                        break;
                }
            }
        }

        return dp.back();
    }
};
