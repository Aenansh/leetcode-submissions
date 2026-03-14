class Solution {
    void backtrack(string& s, int n, int k, int& count, string& res) {
        if (s.length() == n) {
            count++;
            if(count == k) res = s;
            return;
        }

        for (char c = 'a'; c <= 'c'; c++) {
            if (!s.empty() && s.back() == c)
                continue;
            s.push_back(c);
            backtrack(s, n, k, count, res);
            s.pop_back();
        }
    }

public:
    string getHappyString(int n, int k) {
        string res = "", s= "";
        int count = 0;
        backtrack(s, n, k, count, res);
        return res;
    }
};
