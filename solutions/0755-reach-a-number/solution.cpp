class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long pos = 0;
        for (int i = 1; i < INT_MAX; i++) {
            pos += i;
            if ((pos - target) >= 0 && (pos - target) % 2 == 0)
                return i;
        }
        return 0;
    }
};
