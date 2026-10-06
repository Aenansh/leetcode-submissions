class Solution {
public:
    int minAddToMakeValid(string s) {
        int req = 0;
        stack<char> stk;

        for (auto c : s) {
            if (c == '(')
                stk.push(c);
            else {
                if (stk.empty())
                    req++;
                else
                    stk.pop();
            }
        }

        req += stk.size();

        return req;
    }
};
