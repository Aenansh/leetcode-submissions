class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> table;
        for(int i = 0; i < nums.size(); i++){
            if(table[nums[i]] == 2){
                nums.erase(nums.begin() + i);
                i--;
            }
            else{
                table[nums[i]]++;
            }
        }
        return nums.size();
    }
};
