class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int count = 0;
        unordered_map<char, int> mp;
        for (char c : s1)
            mp[c]++;

        for (char c : s2) {
            if (mp.find(c) == mp.end())
                return false;
            mp[c]++;
        }

        for (auto [k, v] : mp) {
            if (v % 2 != 0)
                return false;
        }
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                count++;
        }

        if (count == 0 || count == 2)
            return true;
        return false;
    }
};
