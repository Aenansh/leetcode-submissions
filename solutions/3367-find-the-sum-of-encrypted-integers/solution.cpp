class Solution {
    int encrypt(int x) {
        int bigNum = 0;
        int dummy = x;
        while (dummy) {
            bigNum = max(bigNum, dummy % 10);
            dummy = dummy / 10;
        }
        int ans = 0;
        while (ans < x) {
            ans *= 10;
            ans += bigNum;
        }
        return ans;
    }

public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += encrypt(i);
        }
        return sum;
    }
};
