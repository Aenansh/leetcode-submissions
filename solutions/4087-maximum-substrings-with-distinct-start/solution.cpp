class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> st(begin(s), end(s));
        return st.size();
    }
};
