class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.begin(), nums1.end());
        for(auto i : nums2)
        {
            res.push_back(i);
        }
        sort(res.begin(), res.end());
        if(res.size() == 1) return (double)res[0];
        if(res.size()%2 != 0)
        {
            return (double)res[(int)((res.size() - 1) / 2)];
        }
        else{
            int i1 = res.size() / 2;
            int i2 = i1 - 1;
            double med = (double)(res[i1] + res[i2]) / 2.0;
            return med;
        }
    }
};
