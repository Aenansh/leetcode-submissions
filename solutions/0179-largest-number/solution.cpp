class Solution {
public:
    static bool conComp(string a, string b){
        return a + b > b + a;
    }
    vector<string> lexSort(vector<int>& nums){
        vector<string> s;
        for(auto i : nums){
            s.push_back(to_string(i));
        }
        sort(s.begin(), s.end(), conComp);
        return s;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> s = lexSort(nums);
        string ans = "";
        for(auto i : s){
            ans += i;
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};
