class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            int last1 = arr1.back(), last2 = arr2.back();

            if (last1 > last2) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        arr1.reserve(arr1.size() + arr2.size());
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};
