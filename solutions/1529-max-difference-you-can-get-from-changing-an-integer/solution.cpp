class Solution {
public:
    int maxDiff(int num) {
        string rev = to_string(num);
        char repDig1 = '9';
        char repBy1 = '9';
        for (int i = 0; i < rev.length(); i++) {
            if (rev[i] != '9') {
                repDig1 = rev[i];
                break;
            }
        }
        replace(begin(rev), end(rev), repDig1, repBy1);
        int a = stoi(rev);

        rev = to_string(num);

        if (rev[0] > '1') {
            char r = rev[0];
            replace(begin(rev), end(rev), r, '1');
        } else {
            char repDig2 = '1';
            for (int i = 0; i < rev.length(); i++) {
                if (rev[i] > '1') {
                    repDig2 = rev[i];
                    break;
                }
            }
            if (repDig2 != '1')
                replace(begin(rev), end(rev), repDig2, '0');
        }

        int b = stoi(rev);
        return a - b;
    }
};
