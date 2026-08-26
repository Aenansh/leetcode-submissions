class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int ones = 0, L = 0;
        string ans = "";

        while (s[L] == '0')
            L++;

        for (int R = L; R < n; R++) {
            if (s[R] == '1') {
                ones++;
            }
            while (ones == k) {
                string sub = s.substr(L, R - L + 1);
                if (ans.empty())
                    ans = sub;
                else if (sub.length() < ans.length())
                    ans = sub;
                else if (sub.length() == ans.length() && sub < ans)
                    ans = sub;
                if (s[L] == '1')
                    ones--;
                L++;
            }
        }
        return ans;
    }
};
