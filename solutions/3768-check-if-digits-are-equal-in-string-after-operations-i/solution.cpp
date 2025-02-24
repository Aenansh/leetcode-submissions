class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2){
            string ans = "";
            for(int i = 0; i < s.length() - 1; i++){
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                ans += ((a + b) % 10) + '0';
            }
            s = ans;
        }
        return s[0] == s[1];
    }
};
