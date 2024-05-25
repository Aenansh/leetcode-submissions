class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        for(auto i : nums)
        {
            store.insert(i);
        }
        if(nums.size() != store.size())
        return true;
        return false;
    }
};
