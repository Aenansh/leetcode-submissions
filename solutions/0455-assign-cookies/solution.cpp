class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int i = 0, j = 0, contentKids = 0;
        while (i < m && j < n) {
            if (s[i] >= g[j]) {
                contentKids++;
                j++;
            }
            i++;
        }
        return contentKids;
    }
};
