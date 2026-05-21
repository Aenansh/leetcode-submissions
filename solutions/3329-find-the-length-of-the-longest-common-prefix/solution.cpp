class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> pref1;
        for(auto num : arr1) {
            string p = "";
            string s = to_string(num);
            for(char c : s) {
                p.push_back(c);
                pref1.insert(p);
            }
        }

        int maxLen = 0;
        for(auto num : arr2) {
            string p = "";
            string s = to_string(num);
            for(char c : s) {
                p.push_back(c);
                if(pref1.count(p)) {
                    int len = p.length();
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};
