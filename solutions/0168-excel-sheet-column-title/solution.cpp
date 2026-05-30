class Solution {

public:
    void makeTitle(int n, string& s) {
        if(n == 0) return;
        n = n - 1;
        int q = n / 26;
        int r = n % 26;

        makeTitle(q, s);
        char c = (char)('A' + r);
        s += c;
        return;
    }
    string convertToTitle(int columnNumber) {
        string ans = "";
        makeTitle(columnNumber, ans);

        return ans;
    }
};
