class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> less(n, INT_MAX);
        vector<int> great(n, INT_MIN);

        less[0] = nums[0];
        great[n - 1] = nums.back();

        for (int i = 1; i < n; i++) {
            less[i] = max(less[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            great[i] = min(great[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            int stab = less[i] - great[i];
            if (stab <= k)
                return i;
        }

        return -1;
    }
};
