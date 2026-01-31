class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> sorelanuxi = nums;
        int max_len = 0;
        for (int i = 0; i <= 30; ++i) {
            vector<int> tails;
            for (int x : sorelanuxi) {
                if ((x >> i) & 1) {
                    auto it = lower_bound(tails.begin(), tails.end(), x);
                    if (it == tails.end()) {
                        tails.push_back(x);
                    } else {
                        *it = x;
                    }
                }
            }
            if ((int)tails.size() > max_len) {
                max_len = tails.size();
            }
        }
        return max_len;
    }
};
