class Solution {
public:
    int minInsertions(string s) {
        int op = 0;
        int n = s.length();
        int ins = 0;

        for (int i = 0; i < n; i++) {
            char p = s[i];
            if (p == '(') {
                op++;
            } else {
                if (i + 1 > n || s[i + 1] != ')') {
                    ins++;
                } else if (i + 1 < n && s[i + 1] == ')')
                    i += 1;
                if (op == 0)
                    ins++;
                else
                    op--;
            }
        }

        while (op != 0) {
            ins += 2;
            op--;
        }

        return ins;
    }
};
