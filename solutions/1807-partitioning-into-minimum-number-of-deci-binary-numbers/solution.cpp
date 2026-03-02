class Solution {
public:
    int minPartitions(string n) {
        char a = '0';
        for(char c : n) {
            if(c > a) a = c;
        }
        int ans = a - '0';
        return ans;
    }
};
