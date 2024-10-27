class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            table[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int remains = target - nums[i];
            if(table[remains] && i != table[remains])
            {
                result.push_back(i);
                result.push_back(table[remains]);
                return result;
            }
        }
        result.push_back(-1);
        return result;
    }
};
