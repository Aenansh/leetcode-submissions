class Solution {
public:
    int arrangeCoins(int n) {
        int compRows = 0;
        int dn = n, i = 1;
        while(dn >= i){
            if(dn - i >= 0){
                dn -= i;
                i++;
                compRows++;
            }
        }
        return compRows;
    }
};
