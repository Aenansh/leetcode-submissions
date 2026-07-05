class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.length();
        int m = spaces.size();
        int i = 0, j = 0;
        if (spaces[0] == 0) {
            ans += ' ';
            j++;
        }

        while (i < n || j < m) {
            if (i < n)
                ans.push_back(s[i]);
            if (j < m && i + 1 == spaces[j]) {
                ans.push_back(' ');
                j++;
            }
            i++;
        }
        return ans;
    }
};
