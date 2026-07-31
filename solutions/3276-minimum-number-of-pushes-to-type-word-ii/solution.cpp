class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        for (char ch : word)
            mp[ch]++;

        sort(begin(word), end(word), [&mp](char& a, char& b) {
            if (mp[a] == mp[b])
                return a < b;
            return mp[a] > mp[b];
        });

        int level = 0, mul = 1;
        int pushes = 0;

        for (int i = 0; i < word.length(); i++) {
            if (i - 1 >= 0 && word[i] == word[i - 1])
                continue;
            level++;
            if (level > mul * 8)
                mul++;
            pushes += mp[word[i]] * mul;
        }

        return pushes;
    }
};
