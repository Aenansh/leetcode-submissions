class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }
        if (words.size() != pattern.length())
            return false;

        unordered_map<string, string> mp;
        int n = pattern.length();
        for (int i = 0; i < n; i++) {
            string s1;
            s1.push_back(pattern[i]);
            string s2 = words[i];

            if (mp.find(s1) == mp.end())
                mp[s1] = s2;
            else if (mp.find(s1) != mp.end() && mp[s1] != s2)
                return false;
        }
        mp.clear();
        for (int i = 0; i < n; i++) {
            string s2;
            s2.push_back(pattern[i]);
            string s1 = words[i];

            if (mp.find(s1) == mp.end())
                mp[s1] = s2;
            else if (mp.find(s1) != mp.end() && mp[s1] != s2)
                return false;
        }
        return true;
    }
};
