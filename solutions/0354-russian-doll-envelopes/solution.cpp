class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(begin(envelopes), end(envelopes),
             [&](vector<int>& a, vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 return a[1] > b[1];
             });

        vector<int> dp;

        for (int i = 0; i < n; i++) {
            int h = envelopes[i][1];

            auto it = lower_bound(begin(dp), end(dp), h);

            if (it == end(dp))
                dp.push_back(h);
            else
                *it = h;
        }

        return dp.size();
    }
};
