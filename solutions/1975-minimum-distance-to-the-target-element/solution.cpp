class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int minDis = n;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                minDis = min(minDis, abs(i - start));
            }
        }
        return minDis;
    }
};
