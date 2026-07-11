class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        for (char& c : s) {
            if (c >= 'a' && c <= 'z')
                c = c - 32;
        }

        string ans = "";
        int n = k;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '-')
                continue;
            ans.push_back(s[i]);
            n--;
            if (n == 0) {
                ans.push_back('-');
                n = k;
            }
        }
        if (ans.empty())
            return "";
        if (ans.back() == '-')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
