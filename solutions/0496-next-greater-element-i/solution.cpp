class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> mp;
        for(int i = 0; i < nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        for(int i = 0; i < nums1.size(); i++){
            int k = mp[nums1[i]];
            for(int j = k + 1; j < nums2.size(); j++){
                if(nums2[j] > nums2[k]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};
