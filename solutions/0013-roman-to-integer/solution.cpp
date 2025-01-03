class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> num;
        num['I'] = 1;
        num['V'] = 5;
        num['X'] = 10;
        num['L'] = 50;
        num['C'] = 100;
        num['D'] = 500;
        num['M'] = 1000;

        int n = 0;
        for(int i = 0; i < s.size(); i++){
            if(i < s.size() - 1){
                if(num[s[i]] < num[s[i + 1]]){
                    n -= num[s[i]];
                }
                else{
                    n += num[s[i]];
                }
            }
            else n += num[s[i]];
        }
        return n;
    }
};
