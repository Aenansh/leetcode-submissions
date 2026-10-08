class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string ans = "";

        bool isStart = false;

        for (char c : s) {
            if (!isStart && c == '(') {
                isStart = true;
            } else if (isStart && c == '(') {
                ans += "(";
                stk.push(c);
            } else if (!stk.empty() && isStart && c == ')') {
                stk.pop();
                ans += ")";
            } else if (stk.empty() && c == ')')
                isStart = false;
        }

        return ans;
    }
};
