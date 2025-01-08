class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2) {
        if(s1 == "" || s2 == "") return false;
        return s2.substr(0, s1.length()) == s1 &&
               s2.substr(s2.length() - s1.length()) == s1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }
};
