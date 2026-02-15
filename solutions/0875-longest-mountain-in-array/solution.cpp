class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if (arr.size() < 3)
            return 0;
        int n = arr.size();
        int base = 0, maxHeight = 0;
        while (base < n - 1) {
            int end = base;
            if (end < n - 1 && arr[end] < arr[end + 1]) {
                while (end < n - 1 && arr[end] < arr[end + 1])
                    end++;
                if (end < n - 1 && arr[end] > arr[end + 1]) {
                    while (end < n - 1 && arr[end] > arr[end + 1])
                        end++;
                    maxHeight = max(maxHeight, end - base + 1);
                }
            }
            base = max(base + 1, end);
        }
        return maxHeight;
    }
};
