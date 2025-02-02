class Solution {
public:
    string reverseOnlyLetters(string s) {
        int low = 0, high = s.size() - 1;
        while(low <= high){
            if(!isalpha(s[low])) low++;
            if(!isalpha(s[high])) high--;
            else if(isalpha(s[low]) && isalpha(s[high])){
                swap(s[low], s[high]);
                low++;
                high--;
            }
        }
        return s;
    }
};
