class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> table;
        for(int i : arr1) {
            table[i]++;
        }
        vector<int> ans;
        for(int i : arr2) {
            while(table[i]) {
                ans.push_back(i);
                table[i]--;
            }
        }
        for(auto i : table) {
            if(i.second != 0) {
                while(i.second > 0) {
                    ans.push_back(i.first);
                    i.second--;
                }
            }
        }
        return ans;
    }
};
