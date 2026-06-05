class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] +
                                                nums[right];
                    if (sum == target) {
                        ans.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left + 1] == nums[left])
                            left++;
                        while (left < right && nums[right - 1] == nums[right])
                            right--;

                        left++, right--;
                    } else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return ans;
    }
};
