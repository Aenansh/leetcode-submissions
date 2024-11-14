class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cnt;
        for(char c: s)
        {
            cnt[c]++;
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(cnt[s[i]] == 1)
            return i;
        }
        return -1;
    }
};
