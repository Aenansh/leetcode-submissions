class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto i : nums)
        {
            count[i]++;
        }
        int maj = nums.size() / 2;
        for(auto i : count)
        {
            if(i.second > maj)
            return i.first;
        }
        return -1;
    }
};
