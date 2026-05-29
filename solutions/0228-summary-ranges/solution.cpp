class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n < 1)
            return {};
        long long L = nums[0], R = L;
        vector<string> ans;

        for (int i = 1; i < n; i++) {
            if (nums[i] - R == 1)
                R = nums[i];
            else {
                if (L == R)
                    ans.push_back(to_string(L));
                else {
                    string s = to_string(L) + "->" + to_string(R);
                    ans.push_back(s);
                }
                L = R = nums[i];
            }
        }
        if (L == R)
            ans.push_back(to_string(L));
        else {
            string s = to_string(L) + "->" + to_string(R);
            ans.push_back(s);
        }
        return ans;
    }
};
