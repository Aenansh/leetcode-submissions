class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            int rep = 26 - (int)(s[i] - 'a');
            ans += rep * (i + 1);
        }

        return ans;
    }
};
