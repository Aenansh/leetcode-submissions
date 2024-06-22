class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int maxsubs = 0;
        unordered_map<char, int> mp;
        while(j < s.size())
        {
            if(mp.count(s[j]) == 0 || mp[s[j]] < i)
            {
                mp[s[j]] = j;
                maxsubs = max(maxsubs, j - i + 1);
            }
            else
            {
                i = mp[s[j]] + 1;
                mp[s[j]] = j;
            }
            j++;
        }
        return maxsubs;
    }
}; 
