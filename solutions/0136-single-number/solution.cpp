class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto i : nums)
        {
            count[i]++;
        }
        for(auto i : count)
        {
            if(i.second == 1)
            return i.first;
        }
        return 0;
    }
};
