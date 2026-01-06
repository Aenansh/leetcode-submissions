class Solution {
public:
    void function(vector<string> &ans, string s, int open, int close) {
        if(open == 0 && close == 0)  {
            ans.push_back(s);
            return;
        }
        if(open > 0) {
            function(ans, s + "(", open - 1, close);
        }

        if(close > open) {
            function(ans, s + ")", open, close - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function(ans, "", n, n);
        return ans;
    }
};
