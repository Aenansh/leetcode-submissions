class Solution {
public:
    int minOperations(string s) {
        string s1 = "1";
        string s2 = "0";
        for(int i = 1; i < s.length(); i++) {
            s1 += s1[i - 1] == '1' ? "0" : "1";
            s2 += s2[i - 1] == '1' ? "0" : "1";
        }
        int c1 = 0, c2 = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] != s1[i]) c1++;
            if(s[i] != s2[i]) c2++;
        }

        return min(c1, c2);
    }
};
