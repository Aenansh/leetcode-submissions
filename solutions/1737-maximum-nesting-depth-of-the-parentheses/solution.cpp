class Solution {
public:
    int maxDepth(string s) {
        stack<char> k;
        int maxDepth = 0;

        for (char c : s) {
            if (c == '(') {
                k.push(c);
                int sz = k.size();
                maxDepth = max(maxDepth, sz);
            } else if (c == ')') {
                k.pop();
            }
        }

        return maxDepth;
    }
};
