class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        unordered_map<string, int> mpp1;
        string word;
        while (ss1 >> word)
            mpp1[word]++;

        stringstream ss2(s2);
        unordered_map<string, int> mpp2;
        while (ss2 >> word)
            mpp2[word]++;

        vector<string> ans;
        for (auto [k, v] : mpp1) {
            if (v == 1 && mpp2.find(k) == mpp2.end())
                ans.push_back(k);
        }
        for (auto [k, v] : mpp2) {
            if (v == 1 && mpp1.find(k) == mpp1.end())
                ans.push_back(k);
        }

        return ans;
    }
};
