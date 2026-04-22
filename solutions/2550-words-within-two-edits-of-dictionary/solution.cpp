class Solution {
    bool maxDiffTwo(string s1, string s2) {
        int diff = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) diff++;
        }
        return diff <= 2;
    }

public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        for (auto s : queries) {
            for (auto d : dictionary) {
                if (maxDiffTwo(d, s)) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
