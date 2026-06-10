class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        int goodPairs = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count[nums[i]]) {
                goodPairs += count[nums[i]];
            }
            count[nums[i]]++;
        }
        return goodPairs;
    }
};
