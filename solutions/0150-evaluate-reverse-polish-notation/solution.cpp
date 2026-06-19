class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                int val = stoi(s);
                nums.push(val);
            } else {
                int A = nums.top();
                nums.pop();
                int B = nums.top();
                nums.pop();
                if (s == "+") {
                    nums.push(B + A);
                } else if (s == "-") {
                    nums.push(B - A);
                } else if (s == "*") {
                    nums.push(B * A);
                } else {
                    nums.push(B / A);
                }
            }
        }
        return nums.top();
    }
};
