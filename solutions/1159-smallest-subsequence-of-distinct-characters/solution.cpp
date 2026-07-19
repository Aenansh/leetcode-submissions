class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> seen(26, false);
        vector<int> lastOcc(26, -1);

        int n = s.length();

        string ans = "";

        for (int i = 0; i < n; i++) {
            lastOcc[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (!seen[ch - 'a']) {
                while (!ans.empty() && ans.back() > ch) {
                    char bck = ans.back();
                    if (lastOcc[bck - 'a'] > i) {
                        ans.pop_back();
                        seen[bck - 'a'] = false;
                    } else
                        break;
                }
                ans.push_back(ch);
                seen[ch - 'a'] = true;
            }
        }
        return ans;
    }
};
