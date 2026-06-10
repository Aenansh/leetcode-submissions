class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xD = abs(x - z);
        int yD = abs(y - z);
        
        if(xD == yD) return 0;
        return xD > yD ? 2 : 1;
    }
};
