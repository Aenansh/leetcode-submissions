class Solution {
    bool isPalindrome(string t) {
        if (t.length() < 2)
            return true;
        string k = t;
        reverse(t.begin(), t.end());
        return t == k;
    }
    void backtrack(vector<vector<string>>& parts, vector<string>& p, string& s,
                   int i) {
        if (i == s.length()) {
            parts.push_back(p);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            string t = s.substr(i, j - i + 1);
            if (isPalindrome(t)) {
                p.push_back(t);
                backtrack(parts, p, s, j + 1);
                p.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> parts;
        vector<string> p;
        backtrack(parts, p, s, 0);
        return parts;
    }
};
