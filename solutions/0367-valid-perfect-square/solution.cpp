class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int low = 1;
        int high = num / 2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            double chk = (double)num / (double)mid;
            if(chk == (double)mid){
                return true;
            }
            else if(chk < (double)mid){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return false;
    }
};
