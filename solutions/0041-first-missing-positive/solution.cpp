class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for (int i : nums) {
            if (i > 0)
                s.insert(i);
        }
        if(s.empty()) return 1;
        int j = 1, num = 0;
        for(auto i : s){
            num = i;
            if(num != j)
            return j;
            j++;
        }
        return num + 1;
    }
};
