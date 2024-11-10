class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cnt;
        for(char i : s)
        {
            cnt[i]++;
        }
        for(auto i : s)
        {
            if(cnt[i] == 1)
            {
                return s.find(i);
            }
        }
        return -1;
    }
};
