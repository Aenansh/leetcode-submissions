class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        if (n <= 2)
            return {1, 2};
        vector<int> indices(2, 0);
        for (int i = 0; i < n - 1; i++) {
            int l = i + 1, r = n - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (numbers[mid] + numbers[i] == target) {
                    indices[0] = i + 1;
                    indices[1] = mid + 1;
                    break;
                } else if (numbers[mid] + numbers[i] < target) {
                    l = mid + 1;
                } else
                    r = mid - 1;
            }
        }
        return indices;
    }
};
