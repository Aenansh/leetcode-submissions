class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> sorted(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            nums[i] = sorted.top();
            sorted.pop(); 
        }
        return nums;
    }
};
