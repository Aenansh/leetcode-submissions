class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for (int num : arr)
            mpp[num]++;

        vector<int> freq;
        for (auto [k, v] : mpp)
            freq.push_back(v);

        sort(begin(freq), end(freq));
        int n = freq.size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i] <= k) {
                k -= freq[i];
                count++;
            } else {
                break;
            }
        }

        return n - count;
    }
};
