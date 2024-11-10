class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> r;
        unordered_map<char, int> m;
        for(char i : ransomNote)
        {
            r[i]++;
        }
        for(char i : magazine)
        {
            m[i]++;
        }
        for(auto i : r)
        {
            if(i.second > m[i.first] || m[i.first] == 0) 
            return false;
        }
        return true;
    }
};
