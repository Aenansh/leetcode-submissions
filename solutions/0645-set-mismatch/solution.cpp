class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> tab(nums.size() + 1, 0);
        for(auto i : nums){
            tab[i - 1] = i;
        }
        auto it = find(tab.begin(), tab.end(), 0);
        int d = distance(tab.begin(), it) + 1;

        unordered_map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
            if(mp[i] > 1) return {i, d};
        }
        return {-1, -1};
    }
};
