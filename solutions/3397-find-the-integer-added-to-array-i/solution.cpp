class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int m = *min_element(begin(nums1), end(nums1));
        int n = *min_element(begin(nums2), end(nums2));

        return n - m;
    }
};
