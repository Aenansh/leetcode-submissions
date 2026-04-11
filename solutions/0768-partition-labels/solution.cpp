class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char, int> lastOcc;
        for(int i = 0; i < n; i++) lastOcc[s[i]] = i;
        vector<int> lens;
        int nextPart = 0, currPos = 0;
        while(currPos < n) {
            nextPart = lastOcc[s[currPos]] + 1;
            for(int i = currPos + 1; i < nextPart; i++) {
                if(lastOcc[s[i]] >= nextPart) nextPart = lastOcc[s[i]] + 1;
            }
            lens.push_back(nextPart - currPos);
            currPos = nextPart;
        }
        return lens;
    }
};
