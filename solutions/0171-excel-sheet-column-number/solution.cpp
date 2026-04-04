class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        vector<int> vals(n, 0);
        for(int i = 0; i < n; i++) {
            vals[i] = (int)(columnTitle[i] - 'A') + 1;
        }
        long long cn = 0;
        for(int i = 0; i < n; i++) {
            int idx = (n - 1) - i;
            cn += pow(26, idx) * vals[i];
        }
        return (int)cn;
    }
};
