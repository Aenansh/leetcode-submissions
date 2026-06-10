class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(char v : address) {
            if(v >= '0' && v <= '9') ans += v;
            else  {
                ans += "[.]";
            }
        }
        return ans;
    }
};
