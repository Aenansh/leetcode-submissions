class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            if(c == ')' || c == ']' || c == '}') {
                if(st.empty()) return false;
                if(c == ')') {
                    char t = st.top();
                    st.pop();
                    if(t != '(') return false;
                }
                else if(c == ']') {
                    char t = st.top();
                    st.pop();
                    if(t != '[') return false;
                }
                else {
                    char t = st.top();
                    st.pop();
                    if(t != '{') return false;
                }
            }
        }
        return st.empty();
    }
};
