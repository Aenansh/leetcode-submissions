class Solution {
    typedef long long LL;
    LL M = 1e9 + 7;

    LL power(LL a, LL b) {
        if (b == 0) return 1;
        LL half = power(a, b / 2);
        LL result = (half * half) % M;
        if (b % 2 == 1) result = (result * a) % M;
        return result;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        if (n == 0) return 0;
        int blockSize = max(1, (int)ceil(sqrt(n)));
        vector<vector<vector<int>>> smallQueries(blockSize);
        
        for (auto& query : queries) {
            int k = query[2];
            if (k >= blockSize) {
                int l = query[0], r = query[1], v = query[3];
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % M;
                }
            } else {
                smallQueries[k].push_back(query);
            }
        }
        vector<LL> diff(n);

        for (int k = 1; k < blockSize; k++) {
            if (smallQueries[k].empty()) continue;
            fill(diff.begin(), diff.end(), 1);
            for (auto& query : smallQueries[k]) {
                int l = query[0], r = query[1], v = query[3];
                
                diff[l] = (diff[l] * v) % M;
                
                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;
                if (next < n) {
                    diff[next] = (diff[next] * power(v, M - 2)) % M;
                }
            }
            for (int i = 0; i < n; i++) {
                if (i - k >= 0) {
                    diff[i] = (diff[i] * diff[i - k]) % M;
                }
            }
            for (int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % M;
            }
        }
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        
        return res;
    }
};
