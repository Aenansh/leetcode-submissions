class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        for (auto c : allowed) {
            mp[c]++;
        }

        int count = 0;

        for (auto word : words) {
            int isallowed = 1;
            for (char c : word) {
                if (mp[c] < 1) {
                    isallowed = 0;
                    break;
                }
            }
            if (isallowed)
                count++;
        }

        return count;
    }
};
