class Solution {
public:
    string reverseByType(string s) {
        stack<char> revAl;
        stack<char> revSp;
        for(char c : s) {
            if(isalpha(c)) revAl.push(c);
            else revSp.push(c);
        }
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) {
                s[i] = revAl.top();
                revAl.pop();
            } else {
                s[i] = revSp.top();
                revSp.pop();
            }
        }
        return s;
    }
};
