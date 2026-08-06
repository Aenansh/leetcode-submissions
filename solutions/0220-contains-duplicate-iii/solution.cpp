class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        int n = nums.size();

        int L = 0;
        set<long long> s;

        for (int R = 0; R < n; R++) {
            long long x = nums[R];
            auto pos = s.lower_bound(x - valueDiff);

            if (pos != s.end() && *pos <= x + valueDiff) {
                return true;
            }

            s.insert(x);

            if (R >= indexDiff) {
                s.erase(nums[L++]);
            }
        }

        return false;
    }
};
