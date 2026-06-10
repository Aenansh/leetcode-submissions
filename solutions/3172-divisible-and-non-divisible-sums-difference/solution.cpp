class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = (n * (n + 1)) / 2;
        int vals = n / m;
        int mulSum = (vals * (vals * m + m)) / 2;

        return sum - 2 * mulSum;
    }
};
