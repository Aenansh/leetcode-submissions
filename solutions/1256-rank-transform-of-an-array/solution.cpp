class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted = arr;
        sort(begin(sorted), end(sorted));

        unordered_map<int, int> ranks;

        int r = 1;
        for (int i = 0; i < n; i++) {
            if (ranks.find(sorted[i]) == ranks.end()) {
                ranks[sorted[i]] = r++;
            }
        }

        vector<int> ranked(n, -1);

        for (int i = 0; i < n; i++) {
            ranked[i] = ranks[arr[i]];
        }

        return ranked;
    }
};
