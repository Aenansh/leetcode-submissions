class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        if (k == 0 || k > arr.size())
            return "";
        unordered_map<string, int> map;
        for (string& str : arr) {
            map[str]++;
        }
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (map.at(arr[i]) == 1) {
                count++;
            }
            if (count == k)
                return arr[i];
        }
        return "";
    }
};
