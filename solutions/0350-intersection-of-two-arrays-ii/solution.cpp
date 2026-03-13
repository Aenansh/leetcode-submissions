class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> h1;
        unordered_map<int, int> h2;
        for(auto& i : nums1) h1[i]++;
        for(auto& i : nums2) h2[i]++;

        vector<int> ans;
        for(auto i : h1) {
            if(h2[i.first]) {
                int times = min(h2[i.first], i.second);
                for(int j = 0; j < times; j++) ans.push_back(i.first);
            }
        }
        return ans;
    }
};
