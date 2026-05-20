class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, bool> Amap; 
        unordered_map<int, bool> Bmap;

        vector<int> ans(n, 0);
        if(A[0] == B[0]) ans[0] = 1;
        Amap[A[0]] = true;
        Bmap[B[0]] = true;

        for(int i = 1; i < n; i++) {
            Amap[A[i]] = true, Bmap[B[i]] = true;
            ans[i] = ans[i - 1];
            if(A[i] == B[i]) ans[i]++;
            else {
                if(Amap[B[i]]) ans[i]++;
                if(Bmap[A[i]]) ans[i]++;
            }
        }
        return ans;
    }
};
