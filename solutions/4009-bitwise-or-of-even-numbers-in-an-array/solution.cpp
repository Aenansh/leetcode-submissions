class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int OR = 0;
        for (int n : nums) {
            if (n % 2 == 0)
                OR = OR | n;
        }
        return OR;
    }
};
