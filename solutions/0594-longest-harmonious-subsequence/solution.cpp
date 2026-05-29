class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freq;

        for(int n : nums) freq[n]++;

        int maxSize = 0;
        for(auto it = freq.begin(); it != prev(freq.end()); it++) {
            int size = it->second;
            if(freq.count(it->first + 1)) {
                size += freq[it->first + 1];
                maxSize = max(maxSize, size);
            }
        }
        return maxSize;
    }
};
