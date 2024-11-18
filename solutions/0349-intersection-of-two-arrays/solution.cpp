class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> coll;
        for(auto i : nums1)
        {
            coll[i]++;
        }
        unordered_map<int, int> see;
        for(auto i : nums2)
        {
            if(coll[i])
            see[i]++;
        }
        vector<int> intsec;
        for(auto i : see)
        {
            intsec.push_back(i.first);
        }
        return intsec;
    }
};
