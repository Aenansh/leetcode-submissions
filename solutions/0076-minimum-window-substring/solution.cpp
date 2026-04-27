class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (n > m)
            return "";

        string ans = "";
        int L = 0;

        unordered_map<char, int> freq;
        unordered_map<char, int> store;
        int found = 0;
        for (char c : t)
            store[c]++;

        int minLen = -1, minStart = 0;
        for (int R = 0; R < m; R++) {
            char c = s[R];
            freq[c]++;
            if (store.count(c) && freq[c] == store[c])
                found++;
            while (L <= R && found == store.size()) {
                if(minLen == -1 || minLen > R - L + 1) {
                    minLen = R - L + 1;
                    minStart = L;
                }
                freq[s[L]]--;
                if (store.count(s[L]) && freq[s[L]] < store[s[L]])
                    found--;
                L++;
            }
        }
        return minLen == -1 ? "" : s.substr(minStart, minLen);
    }
};
