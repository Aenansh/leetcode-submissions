class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(auto i : strs){
            string s = i;
            sort(s.begin(), s.end());
            mp[s].emplace_back(i);
        }
        for(auto i : mp){
            ans.emplace_back(i.second);
        }
        return ans;
    }
};
