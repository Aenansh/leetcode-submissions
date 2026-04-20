class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDis = 0;

        for(int i = n - 1; i >= 1; i--) {
            if(colors[0] != colors[i]) {
                maxDis = max(maxDis, i);
            }
        }
        for(int i = 0; i < n - 1; i++) {
            if(colors[n - 1] != colors[i]) {
                maxDis = max(maxDis, abs(n - 1 - i));
            }
        }
        return maxDis;
    }
};
