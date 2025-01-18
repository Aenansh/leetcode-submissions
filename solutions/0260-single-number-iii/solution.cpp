class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> ans;
        for(auto i : nums) ans[i]++;
        vector<int> a;
        for(auto i : ans){
            if(i.second == 1) a.push_back(i.first);
        }
        return a;
    }
};
