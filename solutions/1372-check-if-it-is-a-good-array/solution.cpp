class Solution {
public:
    int gcd(int a, int b) {
        if (a == 1 || b == 1)
            return 1;
        if (a > b) {
            if (a % b == 0)
                return b;
            else
                return gcd(a % b, b);
        } else {
            if (b % a == 0)
                return a;
            else
                return gcd(a, b % a);
        }
    }
    bool isGoodArray(vector<int>& nums) {
        int currGcd = nums[0];
        for(auto i : nums){
            currGcd = gcd(currGcd, i);
            if(currGcd == 1) return true;
        }
        return false;
    }
};
