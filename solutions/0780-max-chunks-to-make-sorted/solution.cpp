class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0;
        int maxEnc = -1;

        for(int i = 0; i < n; i++) {
            maxEnc = max(maxEnc, arr[i]);

            if(maxEnc == i) chunks++;
        }
        return chunks;
    }
};
