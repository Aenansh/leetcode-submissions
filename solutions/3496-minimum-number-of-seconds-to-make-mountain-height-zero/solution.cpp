class Solution {
    bool check(long long mid, int mountainHeight, vector<int>& workerTimes) {
        int h = 0;
        for (int time : workerTimes) {
            h += sqrt(((2 * mid) / time) + 0.25) - 0.5;
        }
        return h >= mountainHeight;
    }

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxtime = *max_element(workerTimes.begin(), workerTimes.end());
        long long n = (long long)mountainHeight;
        long long left = 1;
        long long right = maxtime * ((n * n + n) / 2);
        if(workerTimes.size() <= 1) return right;
        long long res = INT_MAX;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(mid, mountainHeight, workerTimes)) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};
