class Solution {
    int waviness(int num) {
        if (num < 101)
            return 0;
        int waves = 0;
        string s = to_string(num);
        for (int i = 1; i < s.length() - 1; i++) {
            if ((s[i - 1] < s[i] && s[i + 1] < s[i]) ||
                s[i - 1] > s[i] && s[i + 1] > s[i])
                waves++;
        }
        return waves;
    }

public:
    int totalWaviness(int num1, int num2) {
        if(num2 < 101) return 0;
        int waves = 0;
        for(int i = num1; i <= num2; i++) {
            waves += waviness(i);
        }
        return waves;
    }
};
