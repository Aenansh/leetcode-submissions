class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> diff(n + 1, 0);

        for(auto q : queries) {
            int L = q[0], R = q[1];
            diff[L] += 1;
            diff[R + 1] -= 1;
        }

        int prefix = 0;

        for(int i = 0; i < n; i++) {
            prefix += diff[i];

            if(prefix < nums[i]) return false;
        }

        return true;
    }
};
