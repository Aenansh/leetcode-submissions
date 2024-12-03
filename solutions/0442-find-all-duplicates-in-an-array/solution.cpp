class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> chk;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(chk[nums[i]]){
                ans.push_back(nums[i]);
            }
            else{
                chk[nums[i]]++;
            }
        }
        return ans;
    }
};
