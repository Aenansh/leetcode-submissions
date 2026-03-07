class Solution {
public:
    int minFlips(string s) {
        string ss = s + s;
        string a1 = "1";
        string a2 = "0";

        int n = ss.length();
        for (int i = 1; i < n; i++) {
            a1 += a1[i - 1] == '1' ? "0" : "1";
            a2 += a2[i - 1] == '1' ? "0" : "1";
        }

        int f1 = 0, f2 = 0;
        int ans = n;
        int L = 0;
        for (int i = 0; i < n; i++) {
            if (ss[i] != a1[i])
                f1++;
            if (ss[i] != a2[i])
                f2++;
            if (i - L + 1 > s.length()) {
                if (ss[L] != a1[L])
                    f1--;
                if (ss[L] != a2[L])
                    f2--;
                L++;
            }
            if (i - L + 1 == s.length()) {
                ans = min(ans, f1);
                ans = min(ans, f2);
            }
        }

        return ans;
    }
};
