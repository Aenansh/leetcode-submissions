class Solution {
    void backtrack(vector<string>& ans, string comb, int op, int cl) {
        if (cl == 0 && op == 0) {
            ans.push_back(comb);
            return;
        }

        if (op > 0) {
            backtrack(ans, comb + '(', op - 1, cl);
        }

        if (op < cl) {
            backtrack(ans, comb + ')', op, cl - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", n, n);
        return ans;
    }
};
