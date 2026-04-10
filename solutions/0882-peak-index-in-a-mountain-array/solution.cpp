class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;

        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid == n - 1 && arr[mid - 1] < arr[mid])
                return n - 1;
            else if (mid == 0 && arr[mid + 1] < arr[mid])
                return 0;
            else if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
                r = mid - 1;
            else if (mid + 1 < n && arr[mid + 1] > arr[mid])
                l = mid + 1;
            else return mid;
        }
        return l;
    }
};
