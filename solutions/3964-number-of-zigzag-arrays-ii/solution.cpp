class Solution {
    int mod = 1e9 + 7;
    vector<vector<long long>> matrixMul(vector<vector<long long>>& mat1,
                                        vector<vector<long long>>& mat2) {
        int n = mat1.size();
        vector<vector<long long>> ans(n, vector<long long>(n, 0));

        // Optimal i -> k -> j loop order
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                // Safe, optimal zero-check
                if (mat1[i][k] == 0)
                    continue;

                for (int j = 0; j < n; j++) {
                    // Notice the multiplication (*) instead of addition
                    ans[i][j] =
                        (ans[i][j] + (mat1[i][k] * mat2[k][j]) % mod) % mod;
                }
            }
        }
        return ans;
    }

    vector<vector<long long>> matrixExp(vector<vector<long long>>& mat,
                                        long long b) {
        int n = mat.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (b) {
            if (b & 1) {
                res = matrixMul(res, mat);
            }
            mat = matrixMul(mat, mat);
            b >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        auto U = [&](int v) { return v - 1; };

        auto D = [&](int v) { return m + (v - 1); };

        vector<vector<long long>> T(S, vector<long long>(S, 0));

        for (int v = 1; v <= m; v++) {
            for (int u = 1; u < v; u++) {
                T[U(v)][D(u)] = 1;
            }
            for (int u = v + 1; u <= m; u++) {
                T[D(v)][U(u)] = 1;
            }
        }

        vector<long long> dp2(S, 0);

        for (int v = 1; v <= m; v++) {
            dp2[U(v)] = v - 1;
            dp2[D(v)] = m - v;
        }

        vector<vector<long long>> P = matrixExp(T, n - 2);

        vector<long long> dpn(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                dpn[i] = (dpn[i] + P[i][j] * dp2[j]) % mod;
            }
        }

        long long ans = 0;

        for (long long x : dpn) {
            ans = (ans + x) % mod;
        }

        return ans;
    }
};
