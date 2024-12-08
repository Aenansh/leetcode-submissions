class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int low = 1, high = x;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long midS = (long long)mid*mid;  
            if(midS == x) return mid;
            else if(midS < x){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};
