class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for(int i = 0; i < list1.size(); i++){
            mp[list1[i]] = i + 1;
        }
        int indsum = INT_MAX;
        for(int i = 0; i < list2.size(); i++){
            if(mp[list2[i]]){
                indsum = min(indsum, i + mp[list2[i]] - 1);
            }
        }
        vector<string> ans;
        for(int i = 0; i < list2.size(); i++){
            if(mp[list2[i]] && i + mp[list2[i]] - 1 == indsum){
                ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};
