class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ksum = accumulate(arr.begin(), arr.begin() + k, 0);
        int count = 0, left = 0;
        if(ksum / k >= threshold) count++;
        for(int i = k; i < arr.size(); i++) {
            ksum -= arr[left++];
            ksum += arr[i];
            if(ksum / k >= threshold) count++;
        }
        return count;
    }
};
