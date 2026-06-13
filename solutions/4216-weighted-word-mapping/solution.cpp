class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans= "";
        for(auto word : words) {
            int wordWeight = 0;
            for(char letter : word) {
                wordWeight += weights[letter - 'a'];
            }
            int mod = wordWeight % 26;
            ans += 'z' - mod;
        }
        return ans;
    }
};
