class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleD = 0, doubleD = 0;
        for (int n : nums) {
            if (n <= 9)
                singleD += n;
            else
                doubleD += n;
        }
        return singleD != doubleD;
    }
};
