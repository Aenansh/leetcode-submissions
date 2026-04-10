class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return -1;
        unordered_map<int, vector<int>> tups;
        for (int i = 0; i < n; i++) {
            tups[nums[i]].push_back(i);
        }
        int minDis = INT_MAX;
        for (auto& [k, inds] : tups) {
            if (inds.size() >= 3) {
                for (int i = 0; i < inds.size() - 2; i++) {
                    int dis = abs(inds[i] - inds[i + 1]) + abs(inds[i + 1] - inds[i + 2]) +
                              abs(inds[i + 2] - inds[i]);
                    minDis = min(minDis, dis);
                }
            }
        }
        return minDis == INT_MAX ? -1 : minDis;
    }
};
