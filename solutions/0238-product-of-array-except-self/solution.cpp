class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int zeroCount = 0, zeroInd;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
                zeroInd = i;
            }
        }

        if (zeroCount == 1) {
            int totalProd = 1;
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0)
                    totalProd *= nums[i];
            }
            for (int i = 0; i < n; i++) {
                if (i != zeroInd)
                    ans.push_back(0);
                else
                    ans.push_back(totalProd);
            }
            return ans;
        }

        if (zeroCount > 1) {
            for (int i = 0; i < n; i++) {
                ans.push_back(0);
            }
            return ans;
        }

        long long int totalProd = 1;
        for (int i = 0; i < n; i++) {
            totalProd *= nums[i];
        }

        for(int i = 0; i < n; i++) {
            ans.push_back(totalProd / nums[i]);
        }
        return ans;
    }
};
