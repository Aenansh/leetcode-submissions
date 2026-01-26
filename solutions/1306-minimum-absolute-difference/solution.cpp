class Solution {
public:
    bool isSorted(vector<int> arr) {
        int i = 0, j = arr.size() - 1;
        while (i <= j) {
            if (arr[i] > arr[i + 1] || arr[j] < arr[j - 1])
                return false;
        }
        return true;
    }

    int smallest(vector<int> arr) {
        int small = INT_MAX;
        for(auto i : arr) {
            if(i < small) {
                small = i;
            }
        }
        return small;
    }
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        if (arr.size() == 2) {
            ans.push_back(arr);
            return ans;
        }
        if (!isSorted(arr))
            sort(arr.begin(), arr.end());
        
        vector<int> diff(arr.size(), INT_MAX);
        for(int i = arr.size() - 2; i >= 0; i--) {
            diff[i] = arr[i + 1] - arr[i]; 
        }
        int small = smallest(diff);
        for(int i = 0; i < diff.size() - 1; i++) {
            if(diff[i] == small) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};
