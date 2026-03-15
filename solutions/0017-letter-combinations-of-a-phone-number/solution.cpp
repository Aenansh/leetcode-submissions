class Solution {
public:
    void backtrack(string digits, string& c, vector<string>& res,
                   map<char, string> phone, int ind) {
        if (ind == digits.length()) {
            res.push_back(c);
            return;
        }
        for (int j = 0; j < phone[digits[ind]].length(); j++) {
            c.push_back(phone[digits[ind]][j]);
            backtrack(digits, c, res, phone, ind + 1);
            c.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string comb = "";
        map<char, string> combinations = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        backtrack(digits, comb, res, combinations, 0);
        return res;
    }
};
