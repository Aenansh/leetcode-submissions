class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = 0, n2 = 0;
        if (nums2.size() % 2 != 0) {
            for (auto i : nums1) {
                n1 = n1 ^ i;
            }
        }
        if (nums1.size() % 2 != 0) {
            for (auto i : nums2) {
                n2 = n2 ^ i;
            }
        }
        return n1 ^ n2;
    }
};
