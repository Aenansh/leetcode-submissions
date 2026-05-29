class Solution {
    int sumNum(int num) {
        if (num <= 9)
            return num;
        else
            return (num % 10) + sumNum(num / 10);
    }

public:
    int getLucky(string s, int k) {
        int num = 0;
        for (char c : s) {
            int val = (int)(c - 'a') + 1;
            if (val > 9)
                num = num + sumNum(val);
            else
                num = num + val;
        }
        k = k - 1;
        while (k > 0 && num > 9) {
            num = sumNum(num);
            k--;
        }
        return num;
    }
};
