class Solution {
    void solve(int& num1, int& num2, int& op) {
        if (num1 == 0 || num2 == 0)
            return;
        else if (num1 >= num2) {
            num1 -= num2;
            solve(num1, num2, ++op);
        }
        else if (num1 < num2) {
            num2 -= num1;
            solve(num1, num2, ++op);
        }
    }

public:
    int countOperations(int num1, int num2) {
        int op = 0; 
        solve(num1, num2, op);
        return op; 
        }
};
