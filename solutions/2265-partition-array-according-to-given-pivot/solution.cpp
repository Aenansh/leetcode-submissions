class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);

        int eqToPivot = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[j] = nums[i];
                j++;
            } else if (nums[i] == pivot)
                eqToPivot++;
        }
        for (int i = 0; i < eqToPivot; i++) {
            ans[j] = pivot;
            j++;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) {
                ans[j] = nums[i];
                j++;
            }
        }
        return ans;
    }
};
