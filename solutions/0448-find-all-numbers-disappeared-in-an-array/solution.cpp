class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> table;
        vector<int> out;
        for(int i : nums)
        {
            table[i]++;
        }
        for(int i = 1; i <= nums.size(); i++)
        {
            if(!table[i])
            {
                out.push_back(i);
            }
        }
        return out;
    }
};
