class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mpp1;
        unordered_map<string, int> mpp2;

        for (auto word : words1)
            mpp1[word]++;
        for (auto word : words2)
            mpp2[word]++;

        int count = 0;

        for (auto [k, v] : mpp1) {
            if (v == 1 && mpp2[k] == 1)
                count++;
        }

        return count;
    }
};
