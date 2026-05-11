class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits;
        stack<int> s;

        for (int num : nums) {
            while (num > 0) {
                int v = num % 10;
                s.push(v);
                num = num / 10;
            }
            while (!s.empty()) {
                int t = s.top();
                s.pop();
                digits.push_back(t);
            }
        }
        return digits;
    }
};
