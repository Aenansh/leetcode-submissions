class Solution {
public:
    int findComplement(int num) {
        int dummy = num;
        int set = 0;
        while(dummy > 0){
            set = (set << 1) | 1;
            dummy = dummy >> 1;
        }
        return num ^ set;
    }
};
