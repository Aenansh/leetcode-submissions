class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        if (n <= 1)
            return 0;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        int count = 0;
        for (char c : s)
            mp2[c]++;

        for (int i = 0; i < n - 1; i++) {
            mp1[s[i]]++;
            mp2[s[i]]--;
            if (mp2[s[i]] == 0)
                mp2.erase(s[i]);

            if (mp1.size() == mp2.size())
                count++;
        }

        return count;
    }
};
