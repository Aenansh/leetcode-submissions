class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1) return n;
        int half = n / 2;
        int ans = 1;
        vector<int> v(n + 1, 0);
        v[1] = 1;
        for(int i = 1; i <= half; i++) {
            v[2 * i] = v[i];
            if(2 * i + 1 <= n) {
                v[2 * i + 1] = v[i] + v[i + 1];
                ans = max(ans, v[2 * i + 1]);
            }
        }

        return ans;
    }
};
