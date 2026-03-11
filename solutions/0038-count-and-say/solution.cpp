class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string s = countAndSay(n - 1);

        int count = 1;
        string ans = "";
        for(int i = 1; i < s.length(); i++) {
            if(s[i - 1] != s[i]) {
                ans += to_string(count);
                ans += s[i - 1];
                count = 1;
            }
            else count++;
        }
        ans += to_string(count) + s.back();
        return ans;
    }
};
