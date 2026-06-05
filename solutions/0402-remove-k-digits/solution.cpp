class Solution {
    void trimNum(string& s) {
        string trimmed = "";
        int n = s.length();
        int zeros = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(trimmed == "" && s[i] == '0') zeros++;
            else {
                trimmed += s[i];
            }
        }
        if(trimmed == "" && zeros) s = "0";
        else s = trimmed;
    }
public:
    string removeKdigits(string num, int k) {
        if(k == 0) return num;
        if(k == num.length()) return "0";
        stack<char> s;
        for(char n : num) {
            if(s.empty() || s.top() <= n || k == 0) s.push(n);
            else {
                while(!s.empty() && k > 0 && s.top() > n) {
                    s.pop();
                    k--;
                }
                s.push(n);
            }
        }
        while(k > 0) {
            s.pop();
            k--;
        }
        string ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        trimNum(ans);
        return ans;
    }
};
