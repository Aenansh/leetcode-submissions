class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (((mp.find(arr[i] * 2) != mp.end()) && (i != mp[arr[i] * 2])) ||
                ((arr[i] % 2 == 0) && (mp.find(arr[i] / 2) != mp.end()) &&
                 (i != mp[arr[i] / 2])))
                return true;
            mp[arr[i]] = i;
        }

        return false;
    }
};
