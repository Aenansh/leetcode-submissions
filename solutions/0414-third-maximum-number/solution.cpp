class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i && ans[ans.size() - 1] == nums[i]){
                continue;
            }
            ans.push_back(nums[i]);
        }
        if(ans.size() <= 2){
            return ans[ans.size() - 1]; 
        }
        return ans[ans.size() - 3];
    }
};
