class Solution {
public:
    bool scoreBalance(string s) {
        int totalSum = 0;
        for (char c : s)
            totalSum += (int)(c - 'a') + 1;

        if (totalSum % 2 != 0)
            return false;
        int mid = totalSum / 2;

        int midSum = 0;
        for (char c : s) {
            if (midSum == mid)
                return true;
            midSum += (int)(c - 'a') + 1;
        }
        return false;
    }
};
