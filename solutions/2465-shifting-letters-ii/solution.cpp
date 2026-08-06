class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        vector<int> diff(n + 1, 0);

        for (auto shift : shifts) {
            int L = shift[0], R = shift[1], D = shift[2];
            if (D == 0) {
                diff[L] -= 1;
                diff[R + 1] += 1;
            } else {
                diff[L] += 1;
                diff[R + 1] -= 1;
            }
        }

        int prefix = 0;

        for (int i = 0; i < n; i++) {
            prefix += diff[i];

            int shift = (prefix % 26 + 26) % 26;

            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};
