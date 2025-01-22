class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int numSum = 0;
        for(auto i : nums){
            numSum += i;
        }
        int digSum = 0;
        for(auto i : nums){
            while(i > 0){
                digSum += i%10;
                i /= 10;
            }
        }
        return abs(numSum - digSum);
    }
};
