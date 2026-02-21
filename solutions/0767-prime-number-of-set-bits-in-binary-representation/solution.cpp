class Solution {
public:
    int setBits(int num) {
        int count = 0;
        while(num > 0) {
            count += num & 1;
            num = num >> 1;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        for(int i = left; i <= right; i++) {
            int bits = setBits(i);
            if(primes.count(bits)) count++;
        }
        return count;
    }
};
