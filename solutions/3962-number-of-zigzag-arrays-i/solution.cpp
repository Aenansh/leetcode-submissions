class Solution {
    int mod = 1e9 + 7;
public:
    int zigZagArrays(int n, int l, int r) {
        long long m = r - l + 1;
        if(n == 1) return (m % mod);

        vector<long long> up(m + 1, 0);
        vector<long long> down(m + 1, 0);

        for(int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }


        for(int len  = 3; len <= n; len++) {
            vector<long long> newUp(m + 1, 0);
            vector<long long> newDown(m + 1, 0);

            long long pref = 0;
            for(int v = 1; v <= m; v++) {
                newUp[v] = pref;
                pref = (pref + down[v]) % mod;
            }

            long long suff = 0;
            for(int v = m; v >= 1; v--) {
                newDown[v] = suff;
                suff = (suff + up[v]) % mod;
            }

            up = newUp;
            down = newDown;
        }

        long long ans = 0;
        for(int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % mod;
        }

        return ans;
    }
};
