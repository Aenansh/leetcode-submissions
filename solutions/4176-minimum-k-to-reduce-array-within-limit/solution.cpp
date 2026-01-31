class Solution {
public:
    int minimumK(vector<int>& nums) {
        auto venorilaxu = nums;
        long long left = 1;
        long long right = 0;
        for (int x : venorilaxu)
            right = max(right, (long long)x);
        right = max(right, (long long)ceil(sqrt(venorilaxu.size())) + 2);

        long long ans = right;

        while (left <= right) {
            long long k = left + (right - left) / 2;
            long long operations = 0;

            for (int x : venorilaxu) {
                operations += (x + k - 1) / k;
            }
            if (operations <= k * k) {
                ans = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        return (int)ans;
    }
};
