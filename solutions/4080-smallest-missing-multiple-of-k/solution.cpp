class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> mp(begin(nums), end(nums));

        int mul = 1;
        while (mp.count(k * mul)) {
            mul++;
        }

        return k * mul;
    }
};
