class Solution {
public:
    void backtract(vector<string>& arr, string s, int open, int close, int n) {
        if(open == close && open + close == 0) {
            arr.push_back(s);
            return;
        } 
        if(open > 0) {
            backtract(arr, s + "(", open - 1, close, n);
        }
        if(close > open) {
            backtract(arr, s + ")", open, close - 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        backtract(s, "",n, n, n);
        return s;
    }
};
