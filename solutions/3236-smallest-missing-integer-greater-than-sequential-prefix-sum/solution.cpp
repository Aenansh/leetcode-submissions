class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s;
        int sum = nums[0];
        int next = nums[0];

        s.insert(nums[0]);

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            s.insert(curr);
            if (curr - next == 1) {
                sum += curr;
                next = curr;
            } else
                next = -1;
        }

        while (s.count(sum))
            sum++;

        return sum;
    }
};
