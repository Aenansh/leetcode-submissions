class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            if(map[n] && map[n] != i) {
                return {i, map[n]};
            }
        }
        return {};
    }
};
