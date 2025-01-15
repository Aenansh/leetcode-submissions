class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> track;
        while(n != 1){
            if(track[n]) return false;
            track[n]++;
            int num = 0;
            while(n != 0){
                num += (n % 10) * (n % 10);
                n /= 10;
            }
            n = num;
        }
        return true;
    }
};
