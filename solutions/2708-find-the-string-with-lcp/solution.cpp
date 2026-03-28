class Solution {
    vector<vector<int>> checkLCP(string word) {
        int n = word.length();
        vector<vector<int>> lcp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            lcp[i][n - 1] = (word[i] == word[n - 1]) ? 1 : 0;
        }
        for (int j = 0; j < n; j++) {
            lcp[n - 1][j] = (word[n - 1] == word[j]) ? 1 : 0;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (word[i] == word[j]) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                } else {
                    lcp[i][j] = 0;
                }
            }
        }
        return lcp;
    }

public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '$');
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (lcp[j][i] != 0) {
                    s[i] = s[j];
                    break;
                }
            }

            if (s[i] == '$') {
                vector<bool> forbidden(26, false);
                for (int j = 0; j < i; j++) {
                    if (lcp[j][i] == 0) {
                        forbidden[s[j] - 'a'] = true;
                    }
                }

                for (int k = 0; k < 26; k++) {
                    if (forbidden[k] == false) {
                        s[i] = k + 'a';
                        break;
                    }
                }
                if (s[i] == '$')
                    return "";
            }
        }
        return checkLCP(s) == lcp ? s : "";
    }
};
