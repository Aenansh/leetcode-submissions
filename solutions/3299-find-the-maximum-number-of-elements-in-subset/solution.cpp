class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int maxLen = 0;
        maxLen = mp[1] % 2 == 1 ? mp[1] : mp[1] - 1;

        for (auto [num, _] : mp) {
            if (num == 1)
                continue;
            long long curr = num;
            int len = 0;
            while (mp.count(curr) && mp[curr] > 1) {
                len += 2;
                curr = curr * curr;
            }

            if (mp.count(curr) == 1)
                len += 1;
            else
                len -= 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
