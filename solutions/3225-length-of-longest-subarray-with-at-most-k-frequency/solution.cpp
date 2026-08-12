class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int L = 0;
        int maxLen = 0;

        for(int R = 0; R < n; R++) {
            int curr = nums[R];

            mp[curr]++;

            while(mp[curr] > k) {
                int back = nums[L];
                mp[back]--;
                L++;
            }

            maxLen = max(maxLen, R - L + 1);
        }

        return maxLen;
    }
};
