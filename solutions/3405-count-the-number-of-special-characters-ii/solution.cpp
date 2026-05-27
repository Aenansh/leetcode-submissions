class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;
        for (char c : word) {
            if (!mp.count(c))
                mp[c] += 1;
            mp[c]++;
        }

        int count = 0;

        for (char c : word) {
            if (c >= 'a' && c <= 'z')
                mp[c]--;
            else {
                if (mp[c + 32] == 1 && mp.count(c)) {
                    count++;
                }
                mp.erase(c);
            }
        }
        return count;
    }
};
