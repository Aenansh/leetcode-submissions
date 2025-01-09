class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& i : words) {
            if (pref != "" && pref.length() <= i.length() &&
                i.substr(0, pref.length()) == pref)
                count++;
        }
        return count;
    }
};
