class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        int n = words.size();

        vector<string> res;
        int bit = !groups[0];
        res.push_back(words[0]);

        for (int i = 1; i < n; i++) {
            if (groups[i] == bit) {
                res.push_back(words[i]);
                bit = !bit;
            }
        }

        return res;
    }
};
