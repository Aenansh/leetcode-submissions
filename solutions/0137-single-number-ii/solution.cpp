class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto i : nums)
        {
            cnt[i]++;
        }
        for(auto i : cnt)
        {
            if(i.second == 1)
            return i.first;
        }
        return -1;
    }
};
