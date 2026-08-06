class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n;

        vector<int> codes(total);

        for (int i = 0; i < total; i++) {
            codes[i] = i ^ (i >> 1);
        }

        return codes;
    }
};
