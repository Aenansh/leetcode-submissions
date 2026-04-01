class Solution {
    bool isSame(string& word, string& str, int i, int m) {
        for (int j = 0; j < m; j++) {
            if (word[i] != str[j])
                return false;
            i++;
        }
        return true;
    }

public:
    string generateString(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int N = n + m - 1;
        string ans(N, '$');
        vector<bool> canChange(N, false);
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                int i_ = i;
                for (int j = 0; j < m; j++) {
                    if (ans[i_] != '$' && ans[i_] != str2[j])
                        return "";
                    ans[i_] = str2[j];
                    i_++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (ans[i] == '$') {
                ans[i] = 'a';
                canChange[i] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                if (isSame(ans, str2, i, m)) {
                    bool changed = false;
                    for (int j = i + m - 1; j >= i; j--) {
                        if (canChange[j] == true) {
                            ans[j] = 'b';
                            changed = true;
                            break;
                        }
                    }
                    if (!changed)
                        return "";
                }
            }
        }
        return ans;
    }
};
