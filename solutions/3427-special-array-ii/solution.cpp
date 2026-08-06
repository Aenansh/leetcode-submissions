class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if ((nums[i] ^ nums[i - 1]) % 2 == 0) {
                prefix[i] = prefix[i] + 1;
            }
        }

        vector<bool> ans;

        for (auto query : queries) {
            int s = query[0], e = query[1];
            ans.push_back(prefix[e] - prefix[s] == 0);
        }

        return ans;
    }
};
