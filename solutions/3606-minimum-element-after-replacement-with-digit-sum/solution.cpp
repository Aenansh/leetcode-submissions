class Solution {
    int sum(int num) {
        int ans = 0;
        while(num > 0) {
            ans += num % 10;
            num = num / 10;
        }
        return ans;
    }
public:
    int minElement(vector<int>& nums) {
        int ans = sum(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            int s = sum(nums[i]);
            ans = min(ans, s);
        }
        return ans;
    }
};
