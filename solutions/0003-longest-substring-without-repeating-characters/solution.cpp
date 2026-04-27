class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int L = 0;
        int maxLen = 0;
        unordered_map<char, int> freq;
        for (int R = 0; R < n; R++) {
            char c = s[R];
            freq[c]++;

            while (freq[c] > 1) {
                freq[s[L]]--;
                if (freq.count(s[L]) == 0)
                    freq.erase(s[L]);
                L++;
            }

            maxLen = max(maxLen, R - L + 1);
        }
        return maxLen;
    }
};
