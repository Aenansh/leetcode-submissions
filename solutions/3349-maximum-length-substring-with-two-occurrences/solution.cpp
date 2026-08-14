class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> mp;

        int maxLen = 0;
        int L = 0;
        
        for (int R = 0; R < n; R++) {
            char ch = s[R];
            mp[ch]++;

            while (mp[ch] > 2) {
                int bk = s[L];
                mp[bk]--;
                L++;
            }

            maxLen = max(maxLen, R - L + 1);
        }

        return maxLen;
    }
};
