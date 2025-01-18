class Solution {
public:
    int count1(int n) {
        int count = 0;
        while (n >= 1) {
            if ((n & 1) == 1)
                count++;
            n = n >> 1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> bitv;
        unordered_map<int, int> b;
        for (auto i : arr) {
            b[i] = count1(i);
            bitv.push_back({b[i], i});
        }
        sort(bitv.begin(), bitv.end());
        for(int i = 0; i < arr.size(); i++){
            arr[i] = bitv[i][1];
        }
        return arr;
    }
};
