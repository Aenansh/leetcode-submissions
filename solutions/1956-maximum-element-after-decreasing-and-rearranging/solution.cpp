class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        if (arr[0] != 1)
            arr[0] = 1;
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) >= 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return *max_element(begin(arr), end(arr));
    }
};
