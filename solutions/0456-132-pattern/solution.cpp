class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;

        int third = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            if (num < third)
                return true;
            while (!s.empty() && num > s.top()) {
                third = s.top();
                s.pop();
            }
            s.push(num);
        }
        return false;
    }
};
