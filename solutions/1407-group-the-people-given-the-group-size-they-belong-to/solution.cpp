class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();

        map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            mpp[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for (auto [size, group] : mpp) {
            if (group.size() == size) {
                ans.push_back(group);
            } else {
                int len = group.size();
                int i = 0;
                while ((i + size - 1) < len) {
                    int X = i, Y = i + size;
                    vector<int> res(group.begin() + X, group.begin() + Y);
                    ans.push_back(res);
                    i = i + size;
                }
            }
        }

        return ans;
    }
};
