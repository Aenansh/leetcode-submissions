class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<int> upperRow(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            vector<int> currRow(m + 1, 0);

            for (int j = 1; j <= m; j++) {
                if (nums1[j - 1] == nums2[i - 1]) {
                    currRow[j] = upperRow[j - 1] + 1;
                } else {
                    currRow[j] = max(currRow[j - 1], upperRow[j]);
                }
            }

            upperRow = currRow;
        }

        return upperRow.back();
    }
};
