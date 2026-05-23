class Solution {
public:
    bool checkString(string s) {
        int flip = 0;

        for(char c : s) {
            if(flip == 0 && c == 'b') flip = 1;
            else if(flip == 1 && c == 'a') return false;
        }
        return true;
    }
};
