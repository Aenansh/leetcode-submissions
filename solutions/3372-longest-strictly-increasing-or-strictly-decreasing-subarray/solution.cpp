class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() < 2) return 1;
        int maxinc = 0, inc = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] > nums[i]){
                inc++;
                maxinc = max(maxinc, inc);
            }
            else{
                maxinc = max(maxinc, inc);
                inc = 1;
            }
        }

        int maxdec = 0, dec = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] < nums[i]){
                dec++;
                maxdec = max(maxdec, dec);
            }
            else{
                maxdec = max(maxdec, dec);
                dec = 1;
            }
        }
        return max(maxinc, maxdec);
    }
};
