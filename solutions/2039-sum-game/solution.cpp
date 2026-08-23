class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int turn = 0;
        int leftSum = 0, rightSum = 0;

        int leftQ = 0, rightQ = 0;

        for(int i = 0; i < n >> 1; i++) {
            if(num[i] == '?') leftQ++;
            else leftSum += num[i] - '0';
        }

        for(int i = n >> 1; i < n; i++) {
            if(num[i] == '?') rightQ++;
            else rightSum += num[i] - '0';
        }

        while(leftQ || rightQ) {
            if(turn == 0) {
                if(leftSum >= rightSum && leftQ) {
                    leftSum += 9;
                    leftQ--;
                } else if(rightSum >= leftSum && rightQ) {
                    rightSum += 9;
                    rightQ--;
                } else if(leftSum >= rightSum && rightQ) {
                    if(rightSum + 9 > leftSum) rightSum += 9;
                    rightQ--;
                } else if(rightSum >= leftSum && leftQ) {
                    if(leftSum + 9 > rightSum) leftSum += 9;
                    leftQ--;
                }
                turn = 1;
            } else {
                if(leftSum <= rightSum && leftQ) {
                    leftSum += min(9, abs(leftSum - rightSum));
                    leftQ--;
                } else if(rightSum <= leftSum && rightQ) {
                    rightSum += min(9, abs(leftSum - rightSum));
                    rightQ--;
                } else if((leftSum < rightSum && !leftQ) || (rightSum < leftSum && !rightQ)) return true;
                turn = 0;
            }
        }

        return leftSum != rightSum;
    }
};
