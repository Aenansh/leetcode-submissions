class Solution {
    int reverseNum(int num) {
        long long rev = 0;
        while (num > 0) {
            rev += (num % 10);
            rev *= 10;
            num = num / 10;
        }
        rev = rev / 10;
        return (int)rev;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int minDis = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) {
                minDis = min(minDis, abs(i - mp[nums[i]]));
            }
            mp[reverseNum(nums[i])] = i;
        }
        return minDis == INT_MAX ? -1 : minDis;
    }
};
