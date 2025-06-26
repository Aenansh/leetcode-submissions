class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> jIx;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key)
                jIx.push_back(i);
        }
        if(jIx.size() == nums.size() || jIx.empty()) return jIx;
        for (int i = 0; i < jIx.size(); i++) {
            for (int j =
                     ((jIx[i] - k) > (res.size() > 0 ? res[res.size() - 1] : 0)
                          ? (jIx[i] - k)
                          : (res.size() > 0 ? res[res.size() - 1] + 1 : 0));
                 j <= jIx[i] + k; j++) {
                if (j < nums.size())
                    res.push_back(j);
            }
        }
        return res;
    }
};
