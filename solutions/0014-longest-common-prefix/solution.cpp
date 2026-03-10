class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        if(prefix == "") return "";
        for(int i = 1; i < strs.size(); i++) {
            int j = 0;
            if(strs[i] == "") return "";
            for(char c : strs[i]) {
                if(prefix[j] != c) {
                    break;
                }
                else j++;
            }
            if(j < 0) return "";
            else {
                prefix = prefix.substr(0, j);
            }
        }

        return prefix;
    }
};
