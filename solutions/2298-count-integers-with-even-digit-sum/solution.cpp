class Solution {
    int sumNum(int num) {
        if (num <= 9)
            return num;
        else
            return (num % 10) + sumNum(num / 10);
    }

public:
    int countEven(int num) {
        if (num <= 1)
            return 0;
        int ans = 0;
        for (int i = 2; i <= num; i++) {
            if (sumNum(i) % 2 == 0)
                ans++;
        }
        return ans;
    }
};
